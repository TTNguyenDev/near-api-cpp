#include <bip3x/utils.h>
#include <bip3x/Bip39Mnemonic.h>
#include <bip3x/HDKeyEncoder.h>
#include <iostream>

using namespace bip3x;

int main(int argc, char** argv) {
    // create random words
    Bip39Mnemonic::MnemonicResult encodedMnemonic = Bip39Mnemonic::generate();
    std::cout << encodedMnemonic.words << std::endl;
    
    // create mnemonic seed
    bytes_64 seed = HDKeyEncoder::makeBip39Seed(encodedMnemonic.words);
    
    // create root key from mnemonic seed
    HDKey bip32RootKey = HDKeyEncoder::makeBip32RootKey(seed);
    
    // and, finally derive keys
    // copy key to leave root key
    HDKey ethereumKey = bip32RootKey;
    // makeExtendedKey modifies source key
    HDKeyEncoder::makeExtendedKey(ethereumKey, "m/44'/60'/0'/0");

    // extended private key
    std::cout << ethereumKey.extPrivateKey.toString() << std::endl;
    
    // private key
    std::cout << ethereumKey.privateKey.toString() << std::endl;
    
    // extended public key
    std::cout << ethereumKey.extPublicKey.toString() << std::endl;
    
    // public key
    std::cout << ethereumKey.publicKey.toString() << std::endl;
    
    // et cetera..

    // the end.
    return 0;
}
