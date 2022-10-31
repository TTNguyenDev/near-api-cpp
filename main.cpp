#include <bip3x/Bip39Mnemonic.h>
#include <bip3x/HDKeyEncoder.h>
#include <bip3x/utils.h>
#include <cstring>
#include <iostream>
#include <vector>

#include <algorithm>
#include <iomanip>
#include <random>
#include <string>

#include "ed25519/ed25519.h"

using namespace bip3x;
using namespace std;

// Indexer
#define INDEXER_SERVICE_URL "https://testnet-api.kitwallet.app"

inline static constexpr const uint8_t Base58Map[] = {
    '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
inline static constexpr const uint8_t AlphaMap[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0xff, 0x11, 0x12, 0x13, 0x14, 0x15, 0xff, 0x16, 0x17, 0x18, 0x19,
    0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
    0xff, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
    0x37, 0x38, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff};

using CodecMapping = struct _codecmapping {
  _codecmapping(const uint8_t *amap, const uint8_t *bmap)
      : AlphaMapping(amap), BaseMapping(bmap) {}
  const uint8_t *AlphaMapping;
  const uint8_t *BaseMapping;
};

std::string Base58Encode(const std::vector<uint8_t> &data,
                         CodecMapping mapping) {
  std::vector<uint8_t> digits((data.size() * 138 / 100) + 1);
  size_t digitslen = 1;
  for (size_t i = 0; i < data.size(); i++) {
    uint32_t carry = static_cast<uint32_t>(data[i]);
    for (size_t j = 0; j < digitslen; j++) {
      carry = carry + static_cast<uint32_t>(digits[j] << 8);
      digits[j] = static_cast<uint8_t>(carry % 58);
      carry /= 58;
    }
    for (; carry; carry /= 58)
      digits[digitslen++] = static_cast<uint8_t>(carry % 58);
  }
  std::string result;
  for (size_t i = 0; i < (data.size() - 1) && !data[i]; i++)
    result.push_back(mapping.BaseMapping[0]);
  for (size_t i = 0; i < digitslen; i++)
    result.push_back(mapping.BaseMapping[digits[digitslen - 1 - i]]);
  return result;
}

std::vector<uint8_t> Base58Decode(const std::string &data,
                                  CodecMapping mapping) {
  std::vector<uint8_t> result((data.size() * 138 / 100) + 1);
  size_t resultlen = 1;
  for (size_t i = 0; i < data.size(); i++) {
    uint32_t carry =
        static_cast<uint32_t>(mapping.AlphaMapping[data[i] & 0x7f]);
    for (size_t j = 0; j < resultlen; j++, carry >>= 8) {
      carry += static_cast<uint32_t>(result[j] * 58);
      result[j] = static_cast<uint8_t>(carry);
    }
    for (; carry; carry >>= 8)
      result[resultlen++] = static_cast<uint8_t>(carry);
  }
  result.resize(resultlen);
  for (size_t i = 0; i < (data.size() - 1) && data[i] == mapping.BaseMapping[0];
       i++)
    result.push_back(0);
  std::reverse(result.begin(), result.end());
  return result;
}

int main(int argc, char **argv) {
  vector<std::string> words = {"despair", "kind",     "grab",     "chicken",
                               "arena",   "marine",   "pair",     "shed",
                               "hobby",   "original", "elephant", "region"};
  // create mnemonic seed
  bytes_64 seed = HDKeyEncoder::makeBip39Seed(words);

  // create root key from mnemonic seed
  HDKey master_key = HDKeyEncoder::ed25519FromSeed(seed);

  HDKeyEncoder::nearDerivePath(master_key);
  unsigned char public_key[32], private_key[64], ed25519_seed[32];

  for (int i = 0; i < 32; i++)
    private_key[i] = master_key.privateKey.cdata()[i];

  ed25519_create_keypair(public_key, private_key,
                         master_key.privateKey.cdata());

  CodecMapping mapping(AlphaMap, Base58Map);
  std::vector<uint8_t> base58_priv, base58_pub;
  for (int i = 0; i < 64; i++) {
    base58_priv.push_back(private_key[i]);
  }
  for (int i = 0; i < 32; i++) {
    base58_pub.push_back(public_key[i]);
  }

  auto pubKey = Base58Encode(base58_pub, mapping);
  auto privKey = Base58Encode(base58_priv, mapping);

  cout << "near public_key: " << pubKey << endl;
  cout << "near private_key: " << privKey << endl;
  return 0;
}

string getAccountByPublicKey(string publicKey) {
  std::string url =
      INDEXER_SERVICE_URL + "/publicKey" + publicKey + "/accounts";
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
