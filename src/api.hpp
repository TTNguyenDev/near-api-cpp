#ifndef API_H
#define API_H

#include <string>
#include <vector>
#include <functional>

#include <bip3x/HDKeyEncoder.h>
#include <cpr/cpr.h>

#include "picojson.h"

#ifdef NEAR_API_CPP_BUILD_DLL
    #define NEAR_API __declspec(dllexport)
#elif defined(NEAR_API_CPP_DLL)
    #define NEAR_API __declspec(dllimport)
#else
    #define NEAR_API
#endif

namespace NearCpp
{
    class NEAR_API Client
    {
    public:
        Client(std::string publicKey) : PublicKey(publicKey) {};
        Client(std::string publicKey, std::string privateKey) : PublicKey(publicKey), PrivateKey(privateKey) {}
        Client(std::vector<std::string> seedWords);

        void SetIndexerUrl(std::string indexerUrl) { IndexerUrl = indexerUrl; }
        void SetRPCUrl(std::string rpcUrl) { RpcUrl = rpcUrl; }

        std::string GetPublicKey() const { return PublicKey; }
        std::string GetPrivateKey() const { return PrivateKey; }
        std::string GetLastError() const { return LastError; }

        bool GetAccounts(std::vector<std::string>& Accounts) const;
        bool Query(std::string contractId, std::string method, std::string args, std::string& outResult) const;

    private:
        std::string PublicKey;
        std::string PrivateKey;
        std::string IndexerUrl, RpcUrl;

        mutable std::string LastError;

        bool ParseResponse(const cpr::Response& r, std::function<bool(picojson::value)> func) const;
        bool ParseIndexerResponse(const cpr::Response& r, std::function<bool(picojson::value)> func) const;
        bool ParseRPCResponse(const cpr::Response& r, std::function<bool(picojson::value)> func) const;
    };
}

#endif