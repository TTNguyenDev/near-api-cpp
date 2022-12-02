#!/usr/bin/env bash

mkdir -p /tmp/pkgs
cmake_bin=$(which cmake)

if [ "${cmake_bin}" == "" ] && [ ! -f "/usr/bin/cmake" ] && [ ! -f "/usr/local/bin/cmake" ]; then
  # fetching cmake
  CMAKE_MAJOR="3.12"
  CMAKE_PATCH="4"
  CMAKE_VERS="${CMAKE_MAJOR}.${CMAKE_PATCH}"
  if [ ! -f "/tmp/pkgs/cmake.sh" ]; then
    curl -Lso /tmp/pkgs/cmake.sh https://cmake.org/files/v${CMAKE_MAJOR}/cmake-${CMAKE_VERS}-Linux-x86_64.sh
  fi

  sh /tmp/pkgs/cmake.sh --skip-license --prefix=/usr
fi
