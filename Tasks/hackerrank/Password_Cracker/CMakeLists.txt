cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(hackerrank-password-cracker)

include(custom_cmake/functions.cmake)

add_subdirectory(libs/libcracker)
add_subdirectory(app)

if(BUILD_TESTING)
	enable_testing()
	add_subdirectory(tests/libcracker)
endif()

