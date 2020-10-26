cmake_minimum_required(VERSION 3.5)
project(practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address -fPIE -pie -fno-omit-frame-pointer -g -Wall -Wextra -Wpedantic -O0")

add_executable(practice ranges.cpp)