# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build

# Include any dependencies generated for this target.
include bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/compiler_depend.make

# Include the progress variables for this target.
include bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip39/test/lib/googletest/googletest/src/gtest-all.cc
bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/bip39/test/lib/googletest/googlemock/gtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o -MF CMakeFiles/gtest.dir/src/gtest-all.cc.o.d -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip39/test/lib/googletest/googletest/src/gtest-all.cc

bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/bip39/test/lib/googletest/googlemock/gtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip39/test/lib/googletest/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/bip39/test/lib/googletest/googlemock/gtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip39/test/lib/googletest/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtestd.a: bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtestd.a: bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build.make
lib/libgtestd.a: bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../../../lib/libgtestd.a"
	cd /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/bip39/test/lib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/bip39/test/lib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build: lib/libgtestd.a
.PHONY : bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build

bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/bip39/test/lib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/clean

bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	cd /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip39/test/lib/googletest/googletest /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/bip39/test/lib/googletest/googlemock/gtest /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bip39/test/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend

