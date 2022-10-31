#ifndef API_H
#define API_H

#include <string>
#include <vector>

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
        Client(std::vector<std::string> Seed);

        void SetUrl(std::string url) { Url = url; }

        std::string GetPublicKey() const { return PublicKey; }
        std::string GetPrivateKey() const { return PrivateKey; }
        std::string GetLastError() const { return LastError; }

        bool GetAccounts(std::vector<std::string>& Accounts);

    private:
        std::string PublicKey;
        std::string PrivateKey;
        std::string Url;
        std::string LastError;
    };
}

#endif