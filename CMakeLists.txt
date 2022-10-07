cmake_minimum_required(VERSION 3.24)

project(near-api-cpp)

set(CMAKE_CXX_STANDARD 17)

# openssl
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

# bip39
add_subdirectory(bip39)
include_directories(SYSTEM bip39/src/include)

# bip44
add_library(bip44
    bip-implement-cpp/src/crypto/hmac_sha512.cpp
    bip-implement-cpp/src/crypto/mnemoniccode.cpp
    bip-implement-cpp/src/crypto/pbkdf2sha512.cpp
    bip-implement-cpp/src/crypto/sha512.cpp
    bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp
    bip-implement-cpp/src/keynode/keynode.cpp
    bip-implement-cpp/src/keynode/logger.cpp)

# cpr
add_subdirectory(cpr)
include_directories(SYSTEM cpr/include)

# ed25519
add_library(ed25519 STATIC
    ed25519/add_scalar.c
    ed25519/fe.c
    ed25519/ge.c
    ed25519/key_exchange.c
    ed25519/keypair.c
    ed25519/sc.c
    ed25519/seed.c
    ed25519/sha512.c
    ed25519/sign.c
    ed25519/verify.c)

# exe
add_executable(near-api-cpp-test main.cpp)
target_link_libraries(near-api-cpp-test bip39 bip44 cpr ed25519)