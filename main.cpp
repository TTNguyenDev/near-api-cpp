#include "api.h"

#include <vector>
#include <string>
#include <iostream>

#define INDEXER_SERVICE_URL "https://testnet-api.kitwallet.app"
#define RPC_URL "https://rpc.testnet.near.org"

int main(int argc, char** argv)
{
    std::vector<std::string> words = { "despair", "kind",     "grab",     "chicken",
                                       "arena",   "marine",   "pair",     "shed",
                                       "hobby",   "original", "elephant", "region" };
    
    NearCpp::Client Client(words);

    std::cout << "Near public key: " << Client.GetPublicKey() << " (" << Client.GetPublicKey().length() << ")\n";
    std::cout << "Near private key: " << Client.GetPrivateKey() << " (" << Client.GetPrivateKey().length() << ")\n\n";

    Client.SetIndexerUrl(INDEXER_SERVICE_URL);
    Client.SetRPCUrl(RPC_URL);

    std::vector<std::string> Accounts;

    if (Client.GetAccounts(Accounts))
    {
        std::cout << "Accounts (" << Accounts.size() << "): ";
        
        for (int i = 0; i < Accounts.size(); ++i)
        {
            std::cout << Accounts[i];

            if (i < Accounts.size() - 1)
            {
                std::cout << ", ";
            }
        }

        std::cout << std::endl;
    }
    else
    {
        std::cout << "Error fetching accounts: " << Client.GetLastError() << std::endl;
    }

    std::cout << std::endl;

    if (Accounts.size() > 0)
    {
        std::string result;

        if (Client.Query("dev-1658773858471-95636275343017", "get_list_chest", "eyJrZXkiOiAiaGFfbm9pX3F1YW5faG9hbl9raWVtX2hhX25vaV92aWV0X25hbSJ9", result))
        {
            std::cout << "Result: " << result << std::endl;
        }
        else
        {
            std::cout << "Error querying: " << Client.GetLastError() << std::endl;
        }
    }

    return 0;
}
