
cmake_minimum_required(VERSION 3.15)

project(valgrind)

set(CMAKE_CXX_STANDARD 11)

# 设置编译器标志
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(01_uninit_ptr 01_uninit_ptr.cpp)
add_executable(02_use_free_memory 02_use_free_memory.cpp)
add_executable(03_overrun_memory 03_overrun_memory.cpp)
add_executable(04_memory_leak 04_memory_leak.cpp)
add_executable(05_mismacth 05_mismacth.cpp)
