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
include CMakeFiles/bip44.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bip44.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bip44.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bip44.dir/flags.make

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.o: CMakeFiles/bip44.dir/flags.make
CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/hmac_sha512.cpp
CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.o: CMakeFiles/bip44.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.o -MF CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.o.d -o CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/hmac_sha512.cpp

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/hmac_sha512.cpp > CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.i

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/hmac_sha512.cpp -o CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.s

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.o: CMakeFiles/bip44.dir/flags.make
CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/mnemoniccode.cpp
CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.o: CMakeFiles/bip44.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.o -MF CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.o.d -o CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/mnemoniccode.cpp

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/mnemoniccode.cpp > CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.i

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/mnemoniccode.cpp -o CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.s

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.o: CMakeFiles/bip44.dir/flags.make
CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp
CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.o: CMakeFiles/bip44.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.o -MF CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.o.d -o CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp > CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.i

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp -o CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.s

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.o: CMakeFiles/bip44.dir/flags.make
CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/sha512.cpp
CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.o: CMakeFiles/bip44.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.o -MF CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.o.d -o CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/sha512.cpp

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/sha512.cpp > CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.i

CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/crypto/sha512.cpp -o CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.s

CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.o: CMakeFiles/bip44.dir/flags.make
CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp
CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.o: CMakeFiles/bip44.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.o -MF CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.o.d -o CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp

CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp > CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.i

CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp -o CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.s

CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.o: CMakeFiles/bip44.dir/flags.make
CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/keynode.cpp
CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.o: CMakeFiles/bip44.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.o -MF CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.o.d -o CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/keynode.cpp

CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/keynode.cpp > CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.i

CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/keynode.cpp -o CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.s

CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.o: CMakeFiles/bip44.dir/flags.make
CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/logger.cpp
CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.o: CMakeFiles/bip44.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.o -MF CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.o.d -o CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/logger.cpp

CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/logger.cpp > CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.i

CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/bip-implement-cpp/src/keynode/logger.cpp -o CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.s

# Object files for target bip44
bip44_OBJECTS = \
"CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.o" \
"CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.o" \
"CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.o" \
"CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.o" \
"CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.o" \
"CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.o" \
"CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.o"

# External object files for target bip44
bip44_EXTERNAL_OBJECTS =

libbip44.a: CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/hmac_sha512.cpp.o
libbip44.a: CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/mnemoniccode.cpp.o
libbip44.a: CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/pbkdf2sha512.cpp.o
libbip44.a: CMakeFiles/bip44.dir/bip-implement-cpp/src/crypto/sha512.cpp.o
libbip44.a: CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/CoinClasses/hdkeys.cpp.o
libbip44.a: CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/keynode.cpp.o
libbip44.a: CMakeFiles/bip44.dir/bip-implement-cpp/src/keynode/logger.cpp.o
libbip44.a: CMakeFiles/bip44.dir/build.make
libbip44.a: CMakeFiles/bip44.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libbip44.a"
	$(CMAKE_COMMAND) -P CMakeFiles/bip44.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bip44.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bip44.dir/build: libbip44.a
.PHONY : CMakeFiles/bip44.dir/build

CMakeFiles/bip44.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bip44.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bip44.dir/clean

CMakeFiles/bip44.dir/depend:
	cd /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles/bip44.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bip44.dir/depend
