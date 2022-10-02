#include <_types/_uint64_t.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

// Cryptography
#include "ed25519/ed25519.h"

// NETWORKING
#include "json.hpp"
#include <cpr/cpr.h>

// Brosh Encoder
#include "borsh.hpp"
#include "sha256.hpp"

using namespace std;
using json = nlohmann::json;

struct Action {
  string methodName;
  string args;
  long gas;
  int deposit;
};

struct Transaction {
  /// An account on which behalf transaction is signed
  string signer_id;
  // /// A public key of the access key which was used to sign an account.
  // /// Access key holds permissions for calling certain kinds of actions.
  string public_key;
  // /// Nonce is used to determine order of transaction in the pool.
  // /// It increments for a combination of `signer_id` and `public_key`
  long nonce;
  // /// Receiver account for this transaction
  string receiver_id;
  // /// The hash of the block in the blockchain on top of which the given
  // transaction is valid
  string block_hash;
  // /// A list of actions to be applied
  vector<Action> actions;
};

struct SignerInfo {
  long nonce;
  string block_hash;
};

const string NEAR_PROVIDER = "https://rpc.testnet.near.org";
const long DEFAULT_GAS = 100000000000000;

SignerInfo signer_info() {
  json body = {{"jsonrpc", "2.0"},
               {"id", "dontcare"},
               {"method", "query"},
               {"params",
                {{"request_type", "view_access_key"},
                 {"finality", "final"},
                 {"account_id", "unify.testnet"},
                 {"public_key",
                  "ed25519:4uv2ajhwfwhoounu5tozc6jyufqvgtxbbuxhkmvscabr"}}}};
  cpr::Response r = cpr::Post(cpr::Url{NEAR_PROVIDER}, cpr::Body{body.dump()},
                              cpr::Header{{"content-type", "application/json"}},
                              cpr::Header{{"accept", "application/json"}});

  json result = json::parse(r.text);
  SignerInfo signer_info;
  signer_info.nonce = result["result"]["nonce"];
  signer_info.block_hash = result["result"]["block_hash"];
  return signer_info;
}

int main() {
  auto account_id = "unify.testnet";
  auto private_key = "426VFPwA79edh3EUnSzzvXVj3VTdrjYaVba89xt7Ywu5Ru1jBopeDvww6"
                     "TtJwYbbMDSipzcUDa1WyEEnCSfADJJT";
  auto public_key = "4UV2ajhwfWhoounU5tozc6JYuFQVgTxBBUxHkMvscAbR";
  // Create a signer with privatekey

  SignerInfo _signer_info = signer_info();

  // Function call
  auto contract_id = "wrap.testnet";
  auto method_name = "ft_transfer";
  auto args =
      "{\"receiver_id\": \"huy_pham.testnet\", \"amount\": \"19\"}"; // String
                                                                     // in
                                                                     // json-format

  Action action;
  action.methodName = "ft_transfer";
  action.args =
      "{\"receiver_id\": \"huy_pham.testnet\", \"amount\": \"19\"}"; // String
                                                                     // in
                                                                     // json-format
  action.gas = DEFAULT_GAS;
  action.deposit = 0;

  // Sign and submit tx
  Transaction tx;
  tx.signer_id = "unify.testnet";
  tx.public_key = public_key;
  tx.nonce = _signer_info.nonce + 1;
  tx.receiver_id = contract_id;
  tx.block_hash = _signer_info.block_hash; // TODO: Convert to vecu8
  tx.actions.push_back(action);

  BorshEncoder encoder;

  encoder.Encode(tx.signer_id, tx.public_key, (uint64_t)tx.nonce,
                 tx.receiver_id, std::pair{tx.block_hash, 32}, tx.actions);
  auto tx_encoded = encoder.GetBuffer();
  SHA256 sha256;
  sha256.update(tx_encoded);
  auto hash = sha256.digest();

  unsigned char *signature;

  ed25519_sign(signature, tx_encoded, tx_encoded.size(), public_key,
               private_key);

  // TODO: Create SignedTx Struct
  // TODO: Broadcast Tx

  delete[] hash;
}
