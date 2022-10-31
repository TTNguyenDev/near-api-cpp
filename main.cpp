#include "api.h"

#include <vector>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    std::vector<std::string> words = { "despair", "kind",     "grab",     "chicken",
                                       "arena",   "marine",   "pair",     "shed",
                                       "hobby",   "original", "elephant", "region" };
    
    std::string PublicKey, PrivateKey;

    NearCpp::KeysFromSeedPhrase(words, PublicKey, PrivateKey);

    std::cout << "Near public key: " << PublicKey << " (" << PublicKey.length() << ")" << std::endl;
    std::cout << "Near private key: " << PrivateKey << " (" << PrivateKey.length() << ")" << std::endl;

    return 0;
}

std::string getAccountByPublicKey(std::string publicKey) {
    //std::string url = INDEXER_SERVICE_URL + std::string("/publicKey") + publicKey + std::string("/accounts");
    return "";
}

