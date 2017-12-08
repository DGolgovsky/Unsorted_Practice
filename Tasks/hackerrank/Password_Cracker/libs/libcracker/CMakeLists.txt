custom_add_library(libcracker)

custom_compiler_opts(libcracker)

target_include_directories(libcracker INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR}/..)

