#!/usr/bin/env bash

set -e

mkdir -p _build && cd _build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DENABLE_TEST=On -DWITH_COVERAGE=Off
cmake --build . --target toolbox-test
if [ -f "./toolbox-test" ]
then
	./toolbox-test
elif [ -f "./bin/toolbox-test" ]
then
	./bin/toolbox-test
fi