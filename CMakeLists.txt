cmake_minimum_required(VERSION 3.2)

project(near-api-cpp)

set(CMAKE_CXX_STANDARD 17)

# openssl set(OPENSSL_USE_STATIC_LIBS TRUE) find_package(OpenSSL REQUIRED)
# include_directories(${OPENSSL_INCLUDE_DIR})

# bip3x
add_subdirectory(bip3x)
include_directories(SYSTEM bip3x/include)

# cpr
add_subdirectory(cpr)
include_directories(SYSTEM cpr/include)

# ed25519
add_library(
  ed25519 STATIC
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

include_directories(SYSTEM ed25519)

# library
add_library(near-api-cpp STATIC api.cpp)
target_link_libraries(near-api-cpp bip39 ed25519 cpr)

# tests
add_executable(near-api-cpp-test main.cpp)
target_link_libraries(near-api-cpp-test near-api-cpp)
