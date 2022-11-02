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

    Client::~Client()
    {
        std::unique_lock<std::mutex> lock(Mutex);
        Cond.wait(lock, [this]() { return NumThreads <= 0; });
    }

    void Client::GetAccounts(std::function<void(bool, std::vector<std::string>)> callback)
    {
        std::ostringstream ss;
        ss << IndexerUrl << "/publicKey/ed25519:" << PublicKey << "/accounts";

        cpr::AsyncResponse r = cpr::GetAsync(cpr::Url { ss.str() });

        Launch([this, r = std::move(r), callback]() mutable {
            std::vector<std::string> accounts;
            auto response = ParseIndexerResponse(r.get());

            if (response.has_value())
            {
                picojson::array accs = response.value().get<picojson::array>();

                for (const picojson::value& acc : accs)
                {
                    accounts.push_back(acc.get<std::string>());
                }

                callback(true, accounts);
            }
            else
            {
                callback(false, accounts);
            }
        });
    }

    void Client::Query(std::string contractId, std::string method, std::string args, std::function<void(bool, std::string)> callback)
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

        Launch([this, r = std::move(r), callback]() mutable {
            auto response = ParseRPCResponse(r);

            if (response.has_value())
            {
                picojson::array result = response.value().get<picojson::object>()["result"].get<picojson::array>();

                std::vector<char> buffer;

                for (const picojson::value value : result)
                {
                    buffer.push_back(static_cast<uint8_t>(value.get<double>()));
                }

                callback(true, buffer.data());
            }
            else
            {
                callback(false, "");
            }
        });
    }

    std::optional<picojson::value> Client::ParseResponse(const cpr::Response& r) const
    {
#ifndef NDEBUG
        std::cout << "Response:" << std::endl;
        std::cout << r.text << std::endl << std::endl;
#endif

        if (r.error)
        {
            LastError = r.error.message;
            return std::nullopt;
        }

        picojson::value v;
        std::string err = picojson::parse(v, r.text);

        if (!err.empty())
        {
            LastError = err;
            return std::nullopt;
        }

        if (cpr::status::is_success(r.status_code))
        {
            return v;
        }

        LastError = "HTTP error " + std::to_string(r.status_code);

        return std::nullopt;
    }

    std::optional<picojson::value> Client::ParseIndexerResponse(const cpr::Response& r) const
    {
        return ParseResponse(r);
    }

    std::optional<picojson::value> Client::ParseRPCResponse(const cpr::Response& r) const
    {
        auto response = ParseResponse(r);
        return response.has_value() ? response.value().get<picojson::object>()["result"] : response;
    }

    template <typename T>
    void Client::Launch(T&& f)
    {
        NumThreads++;

        std::thread([this, f = std::move(f)]() mutable {
            f();
            std::lock_guard<std::mutex> lock(Mutex);
            NumThreads--;
            Cond.notify_all();
        }).detach();
    }
}