cmake_minimum_required(VERSION 3.2)

project(near-api-cpp)

set(CMAKE_CXX_STANDARD 17)

# bip3x
add_subdirectory(thirdparty/bip3x)
include_directories(SYSTEM thirdparty/bip3x/include)

# cpr
add_subdirectory(thirdparty/cpr)
include_directories(SYSTEM thirdparty/cpr/include)

# ed25519
add_library(
  ed25519 STATIC
  thirdparty/ed25519/add_scalar.c
  thirdparty/ed25519/fe.c
  thirdparty/ed25519/ge.c
  thirdparty/ed25519/key_exchange.c
  thirdparty/ed25519/keypair.c
  thirdparty/ed25519/sc.c
  thirdparty/ed25519/seed.c
  thirdparty/ed25519/sha512.c
  thirdparty/ed25519/sign.c
  thirdparty/ed25519/verify.c)

include_directories(SYSTEM thirdparty/ed25519)

# library
add_library(near-api-cpp STATIC src/api.cpp)
target_link_libraries(near-api-cpp bip39 ed25519 cpr)

# tests
add_executable(near-api-cpp-test src/main.cpp)
target_link_libraries(near-api-cpp-test near-api-cpp)
