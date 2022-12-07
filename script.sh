cmake -S . -B build -DENABLE_CONAN=OFF -DBUILD_SHARED_LIBS=OFF
cd build && make
./near-api-cpp-test
cd ..
