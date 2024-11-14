cmake_minimum_required(VERSION 3.15)

project(OmniServe VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "/projects/libarary/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
endif()

set(CMAKE_PREFIX_PATH "/projects/libarary/vcpkg/installed/x64-linux" ${CMAKE_PREFIX_PATH})

message(STATUS "Starting project configuration...")

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Drogon CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)

find_library(UUID_LIB NAMES uuid REQUIRED PATHS /usr/lib/x86_64-linux-gnu)

if (UUID_LIB)
  message(STATUS "UUID library found at: ${UUID_LIB}")
else()
  message(FATAL_ERROR "UUID library not found. Make sure it is installed and available.")
endif()

add_executable(OmniServe src/main.cpp)

target_link_libraries(OmniServe 
  PRIVATE 
  Drogon::Drogon
  gRPC::grpc 
  gRPC::grpc++ 
  protobuf::libprotobuf       
  protobuf::libprotoc         
  JsonCpp::JsonCpp 
  ${UUID_LIB}
)

message(STATUS "OmniServe project setup completed successfully!")
