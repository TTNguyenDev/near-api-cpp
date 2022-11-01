# Install script for directory: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/cmake" TYPE FILE FILES
    "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/bip3x/bip3x-config.cmake"
    "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/bip3x/bip3x-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2" TYPE STATIC_LIBRARY FILES "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/bip3x/lib/libbip39.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/libbip39.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/libbip39.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/libbip39.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2" TYPE STATIC_LIBRARY FILES "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/bip3x/lib/libcbip39.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/libcbip39.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/libcbip39.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/libcbip39.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/src/bindings/cbip39_config.h"
    "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/src/bindings/cbip39.h"
    "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/src/bindings/cbip39_hdkey_encoder.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/include/bip3x")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES
    "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/pkgconfig/bip3x.pc"
    "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/pkgconfig/bip39.pc"
    "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/pkgconfig/cbip39.pc"
    "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/pkgconfig/bip39_jni.pc"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/cmake/bip3x-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/cmake/bip3x-targets.cmake"
         "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/bip3x/CMakeFiles/Export/1770f00a59fb8bb41fda21a1516af2de/bip3x-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/cmake/bip3x-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/cmake/bip3x-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/cmake" TYPE FILE FILES "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/bip3x/CMakeFiles/Export/1770f00a59fb8bb41fda21a1516af2de/bip3x-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/bip3x-2.2/cmake" TYPE FILE FILES "/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip3x/bip3x/CMakeFiles/Export/1770f00a59fb8bb41fda21a1516af2de/bip3x-targets-release.cmake")
  endif()
endif()

