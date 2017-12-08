#!/bin/bash

mkdir build
cd build
cmake -DBUILD_TESTING=ON ..
cmake --build . -- -j2
ctest -j2
valgrind --tool=memcheck --xml=yes --xml-file=./valgrind --gen-suppressions=all --leak-check=full --leak-resolution=med --track-origins=yes ./app/password_cracker

