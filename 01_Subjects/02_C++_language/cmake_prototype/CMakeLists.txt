

cmake_minimum_required(VERSION 3.12)

# project(project_test)
project(project_test LANGUAGES C++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加OpenMP支持
find_package(OpenMP REQUIRED)

# include_directories("include/")

add_executable(${PROJECT_NAME} 01_openmp 01_openmp.cpp)

target_compile_options(${PROJECT_NAME} PUBLIC ${OpenMP_CXX_FLAGS})
target_link_libraries(${PROJECT_NAME} ${OpenMP_CXX_LIBRARIES})
