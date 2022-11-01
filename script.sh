cmake -S . -B build -DBUILD_SHARED_LIBS=OFF
cd build && make
./near-api-cpp-test
cd ..
