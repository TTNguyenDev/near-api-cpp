#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

#include "ed25519/ed25519.h"

// NETWORKING
#include "json.hpp"
#include <cpr/cpr.h>

// contract_id = "contract.testnet"
// signer_id = "signer.testnet"
// signer_key = "ed25519:[SIGNER_SECRET_KEY]"
// args = {"counter": 1, "action": "increase"}
//
// near_provider =
// near_api.providers.JsonProvider("https://rpc.testnet.near.org") key_pair =
// near_api.signer.KeyPair(signer_key) signer =
// near_api.signer.Signer(signer_id, key_pair) account =
// near_api.account.Account(near_provider, signer)
//
// out = account.function_call(contract_id, "counter_set", args)
//
// print(out)

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

const string NEAR_PROVIDER = "https://rpc.testnet.near.org";

int get_nonce() {
  json body = {{"jsonrpc", "2.0"},
               {"id", "dontcare"},
               {"method", "query"},
               {"params",
                {{"request_type", "view_access_key"},
                 {"finality", "final"},
                 {"account_id", "unify.testnet"},
                 {"public_key",
                  "ed25519:4UV2ajhwfWhoounU5tozc6JYuFQVgTxBBUxHkMvscAbR"}}}};
  cpr::Response r = cpr::Post(cpr::Url{NEAR_PROVIDER}, cpr::Body{body.dump()},
                              cpr::Header{{"Content-Type", "application/json"}},
                              cpr::Header{{"accept", "application/json"}});
  // r.status_code;            // 200
  // r.header["content-type"]; // application/json; charset=utf-8
  // r.text;                   // JSON text string

  std::cout << r.status_code << std::endl;
  std::cout << r.text << std::endl;
  return 0;
}

int main() {
  auto account_id = "unify.testnet";
  auto private_key = "426VFPwA79edh3EUnSzzvXVj3VTdrjYaVba89xt7Ywu5Ru1jBopeDvww6"
                     "TtJwYbbMDSipzcUDa1WyEEnCSfADJJT";
  auto public_key = "4UV2ajhwfWhoounU5tozc6JYuFQVgTxBBUxHkMvscAbR";
  // Create a signer with privatekey

  // Get nonce
  get_nonce();
  // Call an http request

  //    http post https://rpc.testnet.near.org jsonrpc=2.0 id=dontcare method=query \
//      params:='{
  //        "request_type": "view_access_key",
  //        "finality": "final",
  //        "account_id": "client.chainlink.testnet",
  //        "public_key":
  //        "ed25519:H9k5eiU4xXS3M4z8HzKJSLaZdqGdGwBG49o7orNC4eZW"
  //      }'

  auto nonce = 101235786000002;

  // Function call
  auto contract_id = "wrap.testnet";
  auto method_name = "ft_transfer";
  auto gas = 100000000000000;
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
  action.gas = 100000000000000;
  action.deposit = 0;

  // Get lastest block_hash
  auto block_hash = "12345";

  // Sign and submit tx
  Transaction tx;
  tx.signer_id = "unify.testnet";
  tx.public_key = public_key;
  tx.nonce = nonce + 1;
  tx.receiver_id = contract_id;
  tx.block_hash = block_hash;
  tx.actions.push_back(action);

  // let transaction = Transaction {
  //     signer_id: self.config.account_id.clone(),
  //     public_key: near_signer.public_key.clone(),
  //     nonce: signer.nonce as u64 + 1,
  //     receiver_id: self.config.ref_contract.parse().unwrap(),
  //     block_hash:
  //     CryptoHash::try_from_slice(&signer.block_hash.unwrap()).unwrap(),
  //     actions,
  // };
}
