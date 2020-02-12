cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(SRT_Test LANGUAGES CXX)

set(TARGET srt_parser)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -O2)

file(GLOB TARGET_SRC
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")

add_library(${TARGET} SHARED ${TARGET_SRC})

set_target_properties(${TARGET} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON)
target_compile_options(${TARGET} PRIVATE -march=native -fPIC -no-pie -mtune=generic -pipe -fstack-protector-strong -fno-plt)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "-Weverything -stdlib=libc++ -pthread")
else()
    set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS
            "-Wctor-dtor-privacy -Wenum-compare -Wfloat-equal -Wnon-virtual-dtor -Woverloaded-virtual -Wredundant-decls")
endif()

target_include_directories(${TARGET} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

add_executable(parser_tests tests.cpp)
target_link_libraries(parser_tests PRIVATE ${TARGET})