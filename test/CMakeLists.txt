cmake_minimum_required(VERSION 3.5)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    client.c
    Makefile
    server.c)

add_executable(test ${SOURCE_FILES})