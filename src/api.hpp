#ifndef API_H
#define API_H

#include <mutex>
#include <atomic>
#include <string>
#include <vector>
#include <thread>
#include <functional>
#include <condition_variable>

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
        
        ~Client();

        Client(const Client& other) = delete;
        Client& operator=(const Client&) = delete;

        void SetIndexerUrl(std::string indexerUrl) { IndexerUrl = indexerUrl; }
        void SetRPCUrl(std::string rpcUrl) { RpcUrl = rpcUrl; }

        std::string GetPublicKey() const { return PublicKey; }
        std::string GetPrivateKey() const { return PrivateKey; }
        std::string GetLastError() const { return LastError; }

        void GetAccounts(std::function<void(bool, std::vector<std::string>)> callback);
        void Query(std::string contractId, std::string method, std::string args, std::function<void(bool, std::string)> callback);

    private:
        std::string PublicKey;
        std::string PrivateKey;
        std::string IndexerUrl, RpcUrl;

        mutable std::string LastError;

        std::mutex Mutex;
        std::condition_variable Cond;
        std::atomic<int> NumThreads = 0;

        std::optional<picojson::value> ParseResponse(const cpr::Response& r) const;
        std::optional<picojson::value> ParseIndexerResponse(const cpr::Response& r) const;
        std::optional<picojson::value> ParseRPCResponse(const cpr::Response& r) const;

        template <typename T>
        void Launch(T&& f);
    };
}

#endif