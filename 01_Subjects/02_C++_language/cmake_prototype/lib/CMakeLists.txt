
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(hellolib LANGUAGES CXX)

# static library
add_library(libtest.a STATIC libtest.hpp Message.cpp)

add_executable(hello_world hello_world.cpp)

target_link_libraries(hello_world message)
