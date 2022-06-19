#!/bin/bash

cmake -D CMAKE_BUILD_TYPE=Debug -D CMAKE_CXX_COMPILER=g++ -D GENERATE_COVERAGE_REPORT=1 -S . -B coverage/Debug
cmake --build coverage/Debug -j $(nproc --all)

cd coverage/Debug
ctest
cd -

echo "Now run: ./scripts/generate_coverage_report.sh coverage/Debug"