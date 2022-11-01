set(BIP3X_VERSION 2.2.1)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was bip3x-config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

set_and_check(BIP3X_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include")
set_and_check(BIP3X_LIB_DIR "${PACKAGE_PREFIX_DIR}/lib/bip3x-2.2")
set(BIP3X_LIBRARIES "bip39;cbip39")

if("1" STREQUAL "1")
	include(CMakeFindDependencyMacro)

find_dependency(Toolbox REQUIRED)
find_dependency(JNI REQUIRED)

endif()

include("${PACKAGE_PREFIX_DIR}/lib/bip3x-2.2/cmake/bip3x-targets.cmake")
