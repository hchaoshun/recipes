cmake_minimum_required(VERSION 2.8)
PROJECT (cppTest)
SET(SRC_LIST main.cpp)
set(CMAKE_CXX_FLAGS "-std=c++17")


# Find required protobuf package
find_package(Protobuf REQUIRED)

include_directories(${PROTOBUF_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS proto/AddressBook.proto)

ADD_EXECUTABLE(cppTest ${SRC_LIST} ${PROTO_SRCS} ${PROTO_HDRS})

target_link_libraries(cppTest ${PROTOBUF_LIBRARIES})