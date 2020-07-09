cmake_minimum_required(VERSION 3.1)
project(untitled3)

set(CMAKE_CXX_FLAGS "-std=c++17 -gdwarf-2 -O3 -Wall -fPIC -fno-omit-frame-pointer")

find_package(nlohmann_json REQUIRED)
AUX_SOURCE_DIRECTORY(. COMMON_FILES)

add_executable(untitled3 ${COMMON_FILES})

target_link_libraries(untitled3 nlohmann_json::nlohmann_json)
