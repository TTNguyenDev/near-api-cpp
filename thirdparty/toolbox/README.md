# ToolBox++

| Bintray | Windows | Linux & macOS |
|:--------:|:---------:|:-----------------:|
|[ ![Download](https://api.bintray.com/packages/edwardstock/conan-public/toolbox%3Aconan-public/images/download.svg) ](https://bintray.com/edwardstock/conan-public/toolbox%3Aconan-public/_latestVersion)|unavailable|[![CircleCI](https://circleci.com/gh/edwardstock/toolbox/tree/master.svg?style=svg)](https://circleci.com/gh/edwardstock/toolbox/tree/master)|



## Reqs
* cmake >= 3.0
* gnu gcc 5+/clang 5+/msvc
* make

## Usage and features

Namespace for all things is toolbox.

What helpers contained:
* **toolbox::strings** - strings helpers like bool hasNum = matches_pattern("\[0-9\]", "my194string"")
* **toolbox::io** - filesystem helpers
* **toolbox::collections** - collections helpers
* **toolbox::data** - bytes buffer helpers
* **toolbox::term** - confirm or prompt for your CLI app
* **toolbox::tlog** - simple thread-safe logger
* **toolbox::time_profiler** - simple time-based profiler

# Add to project
## Using Conan

Add remote:
```bash
conan remote add -f edwardstock https://edwardstock.jfrog.io/artifactory/api/conan/conan
```

```bash
conan install <path/to/your/project> toolbox/3.2.6@edwardstock/latest
```

or using `conanfile.txt`
```ini
[requires]
toolbox/3.2.6@edwardstock/latest

[generators]
cmake
```

## Include to your CMake project
* Add submodule or just clone
  * `git submodule add https://github.com/edwardstock/toolbox.git /path/to/libs/toolbox` 
  * `git clone https://github.com/edwardstock/toolbox.git /path/to/libs/toolbox`
  
* Edit `CMakeLists.txt`:
```cmake
# your executable or library
add_executable(my_executable) 
#or if library
add_library(my_library)

# include module
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/path/to/libs/toolbox)

# link with your project
target_link_libraries(my_[executable|library] toolbox)
```

## Global Install
This library is Header-Only, so build isn't required. But you can install globally:
```bash
git clone https://github.com/edwardstock/toolbox.git toolbox && cd toolbox/build
cmake --build . --target install
```

## Testing
```bash
git clone https://github.com/edwardstock/toolbox.git toolbox && cd toolbox/build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DENABLE_TEST=On
cmake --build . --target toolbox-test
./toolbox-test
```

## Build with CLang on linux
Probably, if you are compiled clang from the sources, linker may not found `libc++.so` in default lib path. You could manually add it to LD_LIBRARY_PATH or using `sudo -s source llvm_config.sh`.

By default, script installs:
* header to: /usr/local/include/toolbox.hpp