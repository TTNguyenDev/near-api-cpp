#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "bip3x::bip39" for configuration "Release"
set_property(TARGET bip3x::bip39 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(bip3x::bip39 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/bip3x-2.2/libbip39.a"
  )

list(APPEND _cmake_import_check_targets bip3x::bip39 )
list(APPEND _cmake_import_check_files_for_bip3x::bip39 "${_IMPORT_PREFIX}/lib/bip3x-2.2/libbip39.a" )

# Import target "bip3x::cbip39" for configuration "Release"
set_property(TARGET bip3x::cbip39 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(bip3x::cbip39 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/bip3x-2.2/libcbip39.a"
  )

list(APPEND _cmake_import_check_targets bip3x::cbip39 )
list(APPEND _cmake_import_check_files_for_bip3x::cbip39 "${_IMPORT_PREFIX}/lib/bip3x-2.2/libcbip39.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
