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
    void NEAR_API KeysFromSeedPhrase(std::vector<std::string> Seed, std::string& PublicKey, std::string& PrivateKey);
}

#endif