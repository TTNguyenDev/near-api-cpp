#include "api.hpp"
#include "base58.hpp"
#include "base64.hpp"

#include <ranges>

#ifndef NDEBUG
#include <iostream>
#endif

#include <ed25519.h>

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

    bool Client::Query(std::string contractId, std::string method, std::string args, std::string& outResult) const
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
        params["args_base64"] = picojson::value(Base64Encode(args));

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