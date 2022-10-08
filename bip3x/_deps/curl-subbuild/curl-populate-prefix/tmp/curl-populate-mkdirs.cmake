# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/_deps/curl-src"
  "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/_deps/curl-build"
  "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/_deps/curl-subbuild/curl-populate-prefix"
  "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/_deps/curl-subbuild/curl-populate-prefix/tmp"
  "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
  "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/_deps/curl-subbuild/curl-populate-prefix/src"
  "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
