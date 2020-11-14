cmake_minimum_required(VERSION 2.8)
PROJECT (cppTest)
set(CMAKE_CXX_FLAGS "-std=c++17")


# Find required protobuf package
find_package(Protobuf REQUIRED)

set(PROTO_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/proto-src)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})

include_directories(${PROTOBUF_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS proto/AddressBook.proto)
set(ALL_PROTO_SRCS ${PROTO_SRCS})
list(APPEND ALL_PROTO_SRCS ${PROTO_SRCS})

message("srcs: " ${PROTO_SRCS})
message("hers: " ${PROTO_HDRS})
message("proto_src_dir: " ${PROTO_SRC_DIR})

ADD_EXECUTABLE(cppTest main.cpp ${ALL_PROTO_SRCS})

target_link_libraries(cppTest ${PROTOBUF_LIBRARIES})