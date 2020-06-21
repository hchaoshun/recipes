cmake_minimum_required(VERSION 3.13)
project(cmaketest)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_SRCS)

# 添加 math 子目录
add_subdirectory(math)

add_executable(cmaketest main.cpp)
target_link_libraries(cmaketest MathFunctions)