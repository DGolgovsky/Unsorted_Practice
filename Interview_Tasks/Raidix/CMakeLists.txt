cmake_minimum_required(VERSION 3.2)
project(server)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(SOURCE_FILES server.c)
add_executable(server ${SOURCE_FILES})