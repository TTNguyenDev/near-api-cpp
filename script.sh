cmake -S . -B build -DENABLE_CONAN=Off 
cd build && make
./near-api-cpp-test
cd ..
