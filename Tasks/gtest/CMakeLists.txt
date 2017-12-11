cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

add_executable(helloworld_cli hello.h hello.cpp main.cpp)

enable_testing()
find_package(GTest REQUIRED)
add_executable(test_hello test_hello.cpp hello.h hello.cpp)
target_include_directories(test_hello PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(test_hello pthread ${GTEST_BOTH_LIBRARIES})

set_target_properties(helloworld_cli test_hello PROPERTIES
    CXX_STANDART 14
    CXX_STANDART_REQUIRED ON
    COMPILE_OPTIONS -Wall -Wextra -Wpedantic
)

add_test(AllTests test_hello)
