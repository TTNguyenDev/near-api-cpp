#include <bip3x/Bip39Mnemonic.h>
#include <bip3x/HDKeyEncoder.h>
#include <bip3x/utils.h>
#include <iostream>
#include <string.h>
#include <vector>

#include <cstring>

using namespace bip3x;
using namespace std;

// Indexer
#define INDEXER_SERVICE_URL "https://testnet-api.kitwallet.app"

int main(int argc, char **argv) {
  // create random words
  // Bip39Mnemonic::MnemonicResult encodedMnemonic = Bip39Mnemonic::generate();
  // std::cout << encodedMnemonic.words << std::endl;
  vector<std::string> words = {"despair", "kind",     "grab",     "chicken",
                               "arena",   "marine",   "pair",     "shed",
                               "hobby",   "original", "elephant", "region"};
  // create mnemonic seed
  bytes_64 seed = HDKeyEncoder::makeBip39Seed(words);
  cout << seed.to_hex() << endl;




  // // create root key from mnemonic seed
  HDKey bip32RootKey = HDKeyEncoder::makeBip32RootKey(seed);
  // cout << "Root key: " << bip32RootKey.curve_info << endl;
  //
  // // and, finally derive keys
  // // copy key to leave root key
  HDKey nearKey = bip32RootKey;

  std::cout << "Before" << endl << nearKey.privateKey.to_hex() << endl;
  std::cout << nearKey.publicKey.to_hex() << endl;
  // // makeExtendedKey modifies source key
  HDKeyEncoder::derivePath(nearKey, "m/44'/397'/0'", true);

  // HDKeyEncoder::makeExtendedKey(nearKey, "m/44'/397'/0'");

  // TODO: get secretKey

  std::cout << "After" << endl << nearKey.privateKey.to_hex() << endl;
  std::cout << nearKey.publicKey.to_hex() << endl;
  // TODO: Recover

  //
  // // extended private key
  // std::cout << ethereumKey.extPrivateKey.toString() << std::endl;
  //
  // // private key
  // std::cout << ethereumKey.privateKey.toString() << std::endl;
  //
  // // extended public key
  // std::cout << ethereumKey.extPublicKey.toString() << std::endl;
  //
  // // public key
  // std::cout << ethereumKey.publicKey.toString() << std::endl;

  // et cetera..

  // the end.
  return 0;
}

// string getAccountByPublicKey(string publicKey) {
//   let url = INDEXER_SERVICE_URL + "/publicKey/" + publicKey + "/accounts";
//
//   // export const CUSTOM_REQUEST_HEADERS = {
//   //   'X-requestor' : 'near',
//   // };
//   //
//   https://testnet-api.kitwallet.app/publicKey/ed25519:4UV2ajhwfWhoounU5tozc6JYuFQVgTxBBUxHkMvscAbR/accounts
// }

// TODO: Validation methods
//  export default (seedPhrase) => {
//      if (seedPhrase.trim().split(/\s+/g).length < 12) {
//          throw new Error('Provided seed phrase must be at least 12 words
//          long');
//      }
//
//      const isValidSeedPhrase = bip39.validateMnemonic(seedPhrase.trim());
//
//      if (!isValidSeedPhrase) {
//          throw new Error('Provided seed phrase is not valid according to
//          bip39-light standard');
//      }
//
//      return isValidSeedPhrase;
//  };
