#include "api.hpp"

#include <iostream>
#include <string>
#include <vector>

#define INDEXER_SERVICE_URL "https://testnet-api.kitwallet.app"
#define RPC_URL "https://rpc.testnet.near.org"

std::string generate_signin_url(std::string contractId,
                                std::string successUrl) {
  NearCpp::Client Client;

  std::cout << "Near public key: " << Client.GetPublicKey() << " ("
            << Client.GetPublicKey().length() << ")\n";

  std::string pubKey = Client.GetPublicKey();
  return "https://wallet.testnet.near.org/login/"
         "?success_url=" +
         successUrl + "&failure_url=" + successUrl +
         "&contract_id=" + contractId + "&public_key=" + pubKey;
}

int main(int argc, char **argv) {
  // std::vector<std::string> words = {
  //     "despair", "kind", "grab",  "chicken",  "arena",    "marine",
  //     "pair",    "shed", "hobby", "original", "elephant", "region"};
  //
  // NearCpp::Client Client(words);
  //
  // std::cout << "Near public key: " << Client.GetPublicKey() << " ("
  //           << Client.GetPublicKey().length() << ")\n";
  // std::cout << "Near private key: " << Client.GetPrivateKey() << " ("
  //           << Client.GetPrivateKey().length() << ")\n\n";
  //
  // Client.SetIndexerUrl(INDEXER_SERVICE_URL);
  // Client.SetRPCUrl(RPC_URL);
  //
  // std::vector<std::string> Accounts;
  //
  // Client.GetAccounts([&](bool success, std::vector<std::string> accounts,
  //                        std::string err) {
  //   if (success) {
  //     std::cout << "Accounts (" << accounts.size() << "): ";
  //
  //     for (int i = 0; i < accounts.size(); ++i) {
  //       std::cout << accounts[i];
  //
  //       if (i < accounts.size() - 1) {
  //         std::cout << ", ";
  //       }
  //     }
  //
  //     std::cout << std::endl;
  //   } else {
  //     std::cout << "Error fetching accounts: " << err << std::endl;
  //   }
  //
  //   std::cout << std::endl;
  //
  //   std::string result;
  //
  //   Client.Query("dev-1641440672601-60716758911821",
  //   "tokens_metadata_of_owner",
  //                "{ \"owner_id\": \"matty.testnet\"}",
  //                [](bool success, std::string result, std::string err) {
  //                  if (success) {
  //                    std::cout << "Result: " << result << std::endl;
  //                  } else {
  //                    std::cout << "Error querying: " << err << std::endl;
  //                  }
  //                });
  // });

  generate_signin_url("abc", "xyz");

  return 0;
}
