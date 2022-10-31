#include <bip3x/Bip39Mnemonic.h>
#include <bip3x/HDKeyEncoder.h>
#include <bip3x/utils.h>
#include <cstring>
#include <iostream>
#include <string.h>
#include <vector>

#include "ed25519/ed25519.h"
#include "ed25519/ge.h"
#include "ed25519/sc.h"

using namespace bip3x;
using namespace std;

// Indexer
#define INDEXER_SERVICE_URL "https://testnet-api.kitwallet.app"

void keypair_from_seed(const unsigned char *seed) {
  byte pk[64];
  byte sk[32];

  for (int i = 0; i < 32; i++) {
    sk[i] = (std::byte)seed[i];
  }
  // crypto_sign_keypair((unsigned char*)&pk, (unsigned char*)&sk);
  // Return pk, sk in hex
}

int main(int argc, char **argv) {
  vector<std::string> words = {"despair", "kind",     "grab",     "chicken",
                               "arena",   "marine",   "pair",     "shed",
                               "hobby",   "original", "elephant", "region"};
  // create mnemonic seed
  bytes_64 seed = HDKeyEncoder::makeBip39Seed(words);
  cout << "SEED: " << seed.to_hex() << endl;

  // create root key from mnemonic seed
  HDKey master_key = HDKeyEncoder::ed25519FromSeed(seed);

  HDKeyEncoder::nearDerivePath(master_key);
  cout << "derivePath: " << master_key.privateKey.to_hex() << endl;
  unsigned char public_key[32], private_key[64], ed25519_seed[32];

  /* create a random seed, and a keypair out of that seed */
  ed25519_create_seed(ed25519_seed);
  ed25519_create_keypair(public_key, private_key, ed25519_seed);
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
//
