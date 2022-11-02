#include "api.hpp"

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

    Client.GetAccounts([&Client](bool success, std::vector<std::string> accounts) {
        if (success)
        {
            std::cout << "Accounts (" << accounts.size() << "): ";

            for (int i = 0; i < accounts.size(); ++i)
            {
                std::cout << accounts[i];

                if (i < accounts.size() - 1)
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
    });

    std::string result;

    Client.Query("dev-1641440672601-60716758911821",
                 "tokens_metadata_of_owner",
                 "{ \"owner_id\": \"matty.testnet\"}",
                 [&Client](bool success, std::string result) {
        if (success)
        {
            std::cout << "Result: " << result << std::endl;
        }
        else
        {
            std::cout << "Error querying: " << Client.GetLastError() << std::endl;
        }
    });

    return 0;
}
