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
include CMakeFiles/ed25519.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ed25519.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ed25519.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ed25519.dir/flags.make

CMakeFiles/ed25519.dir/ed25519/add_scalar.c.o: CMakeFiles/ed25519.dir/flags.make
CMakeFiles/ed25519.dir/ed25519/add_scalar.c.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/add_scalar.c
CMakeFiles/ed25519.dir/ed25519/add_scalar.c.o: CMakeFiles/ed25519.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ed25519.dir/ed25519/add_scalar.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ed25519.dir/ed25519/add_scalar.c.o -MF CMakeFiles/ed25519.dir/ed25519/add_scalar.c.o.d -o CMakeFiles/ed25519.dir/ed25519/add_scalar.c.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/add_scalar.c

CMakeFiles/ed25519.dir/ed25519/add_scalar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed25519.dir/ed25519/add_scalar.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/add_scalar.c > CMakeFiles/ed25519.dir/ed25519/add_scalar.c.i

CMakeFiles/ed25519.dir/ed25519/add_scalar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed25519.dir/ed25519/add_scalar.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/add_scalar.c -o CMakeFiles/ed25519.dir/ed25519/add_scalar.c.s

CMakeFiles/ed25519.dir/ed25519/fe.c.o: CMakeFiles/ed25519.dir/flags.make
CMakeFiles/ed25519.dir/ed25519/fe.c.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/fe.c
CMakeFiles/ed25519.dir/ed25519/fe.c.o: CMakeFiles/ed25519.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ed25519.dir/ed25519/fe.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ed25519.dir/ed25519/fe.c.o -MF CMakeFiles/ed25519.dir/ed25519/fe.c.o.d -o CMakeFiles/ed25519.dir/ed25519/fe.c.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/fe.c

CMakeFiles/ed25519.dir/ed25519/fe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed25519.dir/ed25519/fe.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/fe.c > CMakeFiles/ed25519.dir/ed25519/fe.c.i

CMakeFiles/ed25519.dir/ed25519/fe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed25519.dir/ed25519/fe.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/fe.c -o CMakeFiles/ed25519.dir/ed25519/fe.c.s

CMakeFiles/ed25519.dir/ed25519/ge.c.o: CMakeFiles/ed25519.dir/flags.make
CMakeFiles/ed25519.dir/ed25519/ge.c.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/ge.c
CMakeFiles/ed25519.dir/ed25519/ge.c.o: CMakeFiles/ed25519.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ed25519.dir/ed25519/ge.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ed25519.dir/ed25519/ge.c.o -MF CMakeFiles/ed25519.dir/ed25519/ge.c.o.d -o CMakeFiles/ed25519.dir/ed25519/ge.c.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/ge.c

CMakeFiles/ed25519.dir/ed25519/ge.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed25519.dir/ed25519/ge.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/ge.c > CMakeFiles/ed25519.dir/ed25519/ge.c.i

CMakeFiles/ed25519.dir/ed25519/ge.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed25519.dir/ed25519/ge.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/ge.c -o CMakeFiles/ed25519.dir/ed25519/ge.c.s

CMakeFiles/ed25519.dir/ed25519/key_exchange.c.o: CMakeFiles/ed25519.dir/flags.make
CMakeFiles/ed25519.dir/ed25519/key_exchange.c.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/key_exchange.c
CMakeFiles/ed25519.dir/ed25519/key_exchange.c.o: CMakeFiles/ed25519.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ed25519.dir/ed25519/key_exchange.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ed25519.dir/ed25519/key_exchange.c.o -MF CMakeFiles/ed25519.dir/ed25519/key_exchange.c.o.d -o CMakeFiles/ed25519.dir/ed25519/key_exchange.c.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/key_exchange.c

CMakeFiles/ed25519.dir/ed25519/key_exchange.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed25519.dir/ed25519/key_exchange.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/key_exchange.c > CMakeFiles/ed25519.dir/ed25519/key_exchange.c.i

CMakeFiles/ed25519.dir/ed25519/key_exchange.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed25519.dir/ed25519/key_exchange.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/key_exchange.c -o CMakeFiles/ed25519.dir/ed25519/key_exchange.c.s

CMakeFiles/ed25519.dir/ed25519/keypair.c.o: CMakeFiles/ed25519.dir/flags.make
CMakeFiles/ed25519.dir/ed25519/keypair.c.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/keypair.c
CMakeFiles/ed25519.dir/ed25519/keypair.c.o: CMakeFiles/ed25519.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ed25519.dir/ed25519/keypair.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ed25519.dir/ed25519/keypair.c.o -MF CMakeFiles/ed25519.dir/ed25519/keypair.c.o.d -o CMakeFiles/ed25519.dir/ed25519/keypair.c.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/keypair.c

CMakeFiles/ed25519.dir/ed25519/keypair.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed25519.dir/ed25519/keypair.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/keypair.c > CMakeFiles/ed25519.dir/ed25519/keypair.c.i

CMakeFiles/ed25519.dir/ed25519/keypair.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed25519.dir/ed25519/keypair.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/keypair.c -o CMakeFiles/ed25519.dir/ed25519/keypair.c.s

CMakeFiles/ed25519.dir/ed25519/sc.c.o: CMakeFiles/ed25519.dir/flags.make
CMakeFiles/ed25519.dir/ed25519/sc.c.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sc.c
CMakeFiles/ed25519.dir/ed25519/sc.c.o: CMakeFiles/ed25519.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ed25519.dir/ed25519/sc.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ed25519.dir/ed25519/sc.c.o -MF CMakeFiles/ed25519.dir/ed25519/sc.c.o.d -o CMakeFiles/ed25519.dir/ed25519/sc.c.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sc.c

CMakeFiles/ed25519.dir/ed25519/sc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed25519.dir/ed25519/sc.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sc.c > CMakeFiles/ed25519.dir/ed25519/sc.c.i

CMakeFiles/ed25519.dir/ed25519/sc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed25519.dir/ed25519/sc.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sc.c -o CMakeFiles/ed25519.dir/ed25519/sc.c.s

CMakeFiles/ed25519.dir/ed25519/seed.c.o: CMakeFiles/ed25519.dir/flags.make
CMakeFiles/ed25519.dir/ed25519/seed.c.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/seed.c
CMakeFiles/ed25519.dir/ed25519/seed.c.o: CMakeFiles/ed25519.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ed25519.dir/ed25519/seed.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ed25519.dir/ed25519/seed.c.o -MF CMakeFiles/ed25519.dir/ed25519/seed.c.o.d -o CMakeFiles/ed25519.dir/ed25519/seed.c.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/seed.c

CMakeFiles/ed25519.dir/ed25519/seed.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed25519.dir/ed25519/seed.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/seed.c > CMakeFiles/ed25519.dir/ed25519/seed.c.i

CMakeFiles/ed25519.dir/ed25519/seed.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed25519.dir/ed25519/seed.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/seed.c -o CMakeFiles/ed25519.dir/ed25519/seed.c.s

CMakeFiles/ed25519.dir/ed25519/sha512.c.o: CMakeFiles/ed25519.dir/flags.make
CMakeFiles/ed25519.dir/ed25519/sha512.c.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sha512.c
CMakeFiles/ed25519.dir/ed25519/sha512.c.o: CMakeFiles/ed25519.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/ed25519.dir/ed25519/sha512.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ed25519.dir/ed25519/sha512.c.o -MF CMakeFiles/ed25519.dir/ed25519/sha512.c.o.d -o CMakeFiles/ed25519.dir/ed25519/sha512.c.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sha512.c

CMakeFiles/ed25519.dir/ed25519/sha512.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed25519.dir/ed25519/sha512.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sha512.c > CMakeFiles/ed25519.dir/ed25519/sha512.c.i

CMakeFiles/ed25519.dir/ed25519/sha512.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed25519.dir/ed25519/sha512.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sha512.c -o CMakeFiles/ed25519.dir/ed25519/sha512.c.s

CMakeFiles/ed25519.dir/ed25519/sign.c.o: CMakeFiles/ed25519.dir/flags.make
CMakeFiles/ed25519.dir/ed25519/sign.c.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sign.c
CMakeFiles/ed25519.dir/ed25519/sign.c.o: CMakeFiles/ed25519.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/ed25519.dir/ed25519/sign.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ed25519.dir/ed25519/sign.c.o -MF CMakeFiles/ed25519.dir/ed25519/sign.c.o.d -o CMakeFiles/ed25519.dir/ed25519/sign.c.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sign.c

CMakeFiles/ed25519.dir/ed25519/sign.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed25519.dir/ed25519/sign.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sign.c > CMakeFiles/ed25519.dir/ed25519/sign.c.i

CMakeFiles/ed25519.dir/ed25519/sign.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed25519.dir/ed25519/sign.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/sign.c -o CMakeFiles/ed25519.dir/ed25519/sign.c.s

CMakeFiles/ed25519.dir/ed25519/verify.c.o: CMakeFiles/ed25519.dir/flags.make
CMakeFiles/ed25519.dir/ed25519/verify.c.o: /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/verify.c
CMakeFiles/ed25519.dir/ed25519/verify.c.o: CMakeFiles/ed25519.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/ed25519.dir/ed25519/verify.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ed25519.dir/ed25519/verify.c.o -MF CMakeFiles/ed25519.dir/ed25519/verify.c.o.d -o CMakeFiles/ed25519.dir/ed25519/verify.c.o -c /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/verify.c

CMakeFiles/ed25519.dir/ed25519/verify.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ed25519.dir/ed25519/verify.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/verify.c > CMakeFiles/ed25519.dir/ed25519/verify.c.i

CMakeFiles/ed25519.dir/ed25519/verify.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ed25519.dir/ed25519/verify.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/ed25519/verify.c -o CMakeFiles/ed25519.dir/ed25519/verify.c.s

# Object files for target ed25519
ed25519_OBJECTS = \
"CMakeFiles/ed25519.dir/ed25519/add_scalar.c.o" \
"CMakeFiles/ed25519.dir/ed25519/fe.c.o" \
"CMakeFiles/ed25519.dir/ed25519/ge.c.o" \
"CMakeFiles/ed25519.dir/ed25519/key_exchange.c.o" \
"CMakeFiles/ed25519.dir/ed25519/keypair.c.o" \
"CMakeFiles/ed25519.dir/ed25519/sc.c.o" \
"CMakeFiles/ed25519.dir/ed25519/seed.c.o" \
"CMakeFiles/ed25519.dir/ed25519/sha512.c.o" \
"CMakeFiles/ed25519.dir/ed25519/sign.c.o" \
"CMakeFiles/ed25519.dir/ed25519/verify.c.o"

# External object files for target ed25519
ed25519_EXTERNAL_OBJECTS =

libed25519.a: CMakeFiles/ed25519.dir/ed25519/add_scalar.c.o
libed25519.a: CMakeFiles/ed25519.dir/ed25519/fe.c.o
libed25519.a: CMakeFiles/ed25519.dir/ed25519/ge.c.o
libed25519.a: CMakeFiles/ed25519.dir/ed25519/key_exchange.c.o
libed25519.a: CMakeFiles/ed25519.dir/ed25519/keypair.c.o
libed25519.a: CMakeFiles/ed25519.dir/ed25519/sc.c.o
libed25519.a: CMakeFiles/ed25519.dir/ed25519/seed.c.o
libed25519.a: CMakeFiles/ed25519.dir/ed25519/sha512.c.o
libed25519.a: CMakeFiles/ed25519.dir/ed25519/sign.c.o
libed25519.a: CMakeFiles/ed25519.dir/ed25519/verify.c.o
libed25519.a: CMakeFiles/ed25519.dir/build.make
libed25519.a: CMakeFiles/ed25519.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C static library libed25519.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ed25519.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ed25519.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ed25519.dir/build: libed25519.a
.PHONY : CMakeFiles/ed25519.dir/build

CMakeFiles/ed25519.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ed25519.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ed25519.dir/clean

CMakeFiles/ed25519.dir/depend:
	cd /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build /Users/trietnguyen/Documents/Work/neil_projects/near-api-cpp/build/CMakeFiles/ed25519.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ed25519.dir/depend

