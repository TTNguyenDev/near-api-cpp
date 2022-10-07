cmake_minimum_required(VERSION 3.24)

project(near-api-cpp)

set(CMAKE_CXX_STANDARD 17)

# bip39
add_subdirectory(bip39)
include_directories(SYSTEM bip39/src/include)

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
target_link_libraries(near-api-cpp-test bip39 cpr ed25519)