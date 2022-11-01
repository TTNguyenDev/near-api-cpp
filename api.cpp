#include "api.h"
#include "api.h"
#include "api.h"

#ifndef NDEBUG
#include <iostream>
#endif

#include <ed25519.h>

inline static constexpr const uint8_t Base58Map[] = {
    '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

inline static constexpr const uint8_t AlphaMap[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0xff, 0x11, 0x12, 0x13, 0x14, 0x15, 0xff, 0x16, 0x17, 0x18, 0x19,
    0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
    0xff, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
    0x37, 0x38, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff };

struct CodecMapping
{
    CodecMapping(const uint8_t* amap, const uint8_t* bmap) : AlphaMapping(amap), BaseMapping(bmap) {}
    const uint8_t* AlphaMapping;
    const uint8_t* BaseMapping;
};

std::string Base58Encode(const std::vector<uint8_t>& data, CodecMapping mapping)
{
    std::vector<uint8_t> digits((data.size() * 138 / 100) + 1);
    size_t digitslen = 1;

    for (size_t i = 0; i < data.size(); i++)
    {
        uint32_t carry = static_cast<uint32_t>(data[i]);

        for (size_t j = 0; j < digitslen; j++)
        {
            carry = carry + static_cast<uint32_t>(digits[j] << 8);
            digits[j] = static_cast<uint8_t>(carry % 58);
            carry /= 58;
        }

        for (; carry; carry /= 58)
        {
            digits[digitslen++] = static_cast<uint8_t>(carry % 58);
        }
    }

    std::string result;

    for (size_t i = 0; i < (data.size() - 1) && !data[i]; i++)
    {
        result.push_back(mapping.BaseMapping[0]);
    }

    for (size_t i = 0; i < digitslen; i++)
    {
        result.push_back(mapping.BaseMapping[digits[digitslen - 1 - i]]);
    }

    return result;
}

std::vector<uint8_t> Base58Decode(const std::string& data, CodecMapping mapping)
{
    std::vector<uint8_t> result((data.size() * 138 / 100) + 1);
    size_t resultlen = 1;

    for (size_t i = 0; i < data.size(); i++)
    {
        uint32_t carry = static_cast<uint32_t>(mapping.AlphaMapping[data[i] & 0x7f]);

        for (size_t j = 0; j < resultlen; j++, carry >>= 8)
        {
            carry += static_cast<uint32_t>(result[j] * 58);
            result[j] = static_cast<uint8_t>(carry);
        }

        for (; carry; carry >>= 8)
        {
            result[resultlen++] = static_cast<uint8_t>(carry);
        }
    }

    result.resize(resultlen);

    for (size_t i = 0; i < (data.size() - 1) && data[i] == mapping.BaseMapping[0]; i++)
    {
        result.push_back(0);
    }

    std::reverse(result.begin(), result.end());

    return result;
}

namespace NearCpp
{
    Client::Client(std::vector<std::string> seedWords)
    {
        // create mnemonic seed
        bip3x::bytes_64 seed = bip3x::HDKeyEncoder::makeBip39Seed(seedWords);

        // create root key from mnemonic seed
        bip3x::HDKey master_key = bip3x::HDKeyEncoder::ed25519FromSeed(seed);

        bip3x::HDKeyEncoder::nearDerivePath(master_key);
        unsigned char public_key[32], private_key[64];

        ed25519_create_keypair(public_key, private_key, master_key.privateKey.cdata());

        CodecMapping mapping(AlphaMap, Base58Map);
        std::vector<uint8_t> base58_priv, base58_pub;

        for (int i = 0; i < 64; i++)
        {
            base58_priv.push_back(private_key[i]);
        }

        for (int i = 0; i < 32; i++)
        {
            base58_pub.push_back(public_key[i]);
        }

        PublicKey = Base58Encode(base58_pub, mapping);
        PrivateKey = Base58Encode(base58_priv, mapping);
    }

    bool Client::GetAccounts(std::vector<std::string>& Accounts) const
    {
        Accounts.clear();

        std::ostringstream ss;
        ss << IndexerUrl << "/publicKey/ed25519:" << PublicKey << "/accounts";

        cpr::Response r = cpr::Get(cpr::Url { ss.str() });

        return ParseIndexerResponse(r, [&Accounts](picojson::value v) {
            picojson::array accs = v.get<picojson::array>();

            for (const picojson::value& acc : accs)
            {
                Accounts.push_back(acc.get<std::string>());
            }

            return true;
        });
    }

    bool Client::Query(std::string contractId, std::string method, std::string argsBase64, std::string& outResult) const
    {
        picojson::object obj;
        obj["jsonrpc"] = picojson::value("2.0");
        obj["id"] = picojson::value("dontcare");
        obj["method"] = picojson::value("query");

        picojson::object params;
        params["request_type"] = picojson::value("call_function");
        params["finality"] = picojson::value("final");
        params["account_id"] = picojson::value(contractId);
        params["method_name"] = picojson::value(method);
        params["args_base64"] = picojson::value(argsBase64);

        obj["params"] = picojson::value(params);

        picojson::value payload(obj);

        cpr::Response r = cpr::Post(cpr::Url { RpcUrl },
            cpr::Body { payload.serialize() },
            cpr::Header {{ "Content-Type", "application/json" }});

#ifndef NDEBUG
        std::cout << "Payload:" << std::endl;
        std::cout << payload.serialize(true) << std::endl << std::endl;
#endif

        return ParseRPCResponse(r, [&outResult](picojson::value v) {
            picojson::array result = v.get<picojson::object>()["result"].get<picojson::array>();

            std::vector<char> buffer;

            for (const picojson::value value : result)
            {
                buffer.push_back(static_cast<uint8_t>(value.get<double>()));
            }

            outResult = buffer.data();

            return true;
        });
    }

    bool Client::ParseResponse(const cpr::Response& r, std::function<bool(picojson::value)> func) const
    {
#ifndef NDEBUG
        std::cout << "Response:" << std::endl;
        std::cout << r.text << std::endl << std::endl;
#endif

        if (r.error)
        {
            LastError = r.error.message;
            return false;
        }

        picojson::value v;
        std::string err = picojson::parse(v, r.text);

        if (!err.empty())
        {
            LastError = err;
            return false;
        }

        if (cpr::status::is_success(r.status_code))
        {
            return func(v);
        }

        return false;
    }

    bool Client::ParseIndexerResponse(const cpr::Response& r, std::function<bool(picojson::value)> func) const
    {
        return ParseResponse(r, func);
    }

    bool Client::ParseRPCResponse(const cpr::Response& r, std::function<bool(picojson::value)> func) const
    {
        return ParseResponse(r, [&func](picojson::value v) {
            return func(v.get<picojson::object>()["result"]);
        });
    }
}