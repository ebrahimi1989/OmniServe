cmake_minimum_required(VERSION 3.15)

# Define the project
project(OmniServe VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Log the start of the configuration
message(STATUS "Starting project configuration...")

# Enable verbose output for better logging
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set the path where external dependencies will be downloaded
set(FETCH_CONTENT_QUIET FALSE)

# Include FetchContent module for downloading dependencies
include(FetchContent)

# --- Fetch Drogon ---
message(STATUS "Fetching Drogon...")
FetchContent_Declare(
  Drogon
  GIT_REPOSITORY https://github.com/drogonframework/drogon.git
  GIT_TAG master
)
FetchContent_MakeAvailable(Drogon)

# --- Fetch gRPC ---
message(STATUS "Fetching gRPC...")
FetchContent_Declare(
  gRPC
  GIT_REPOSITORY https://github.com/grpc/grpc.git
  GIT_TAG v1.48.0  # Choose the gRPC version you want
)
FetchContent_MakeAvailable(gRPC)

# --- Fetch JsonCpp ---
message(STATUS "Fetching JsonCpp...")
FetchContent_Declare(
  JsonCpp
  GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
  GIT_TAG master
)
FetchContent_MakeAvailable(JsonCpp)

# --- Create the Executable ---
message(STATUS "Creating executable...")
add_executable(OmniServe main.cpp)

# Link the libraries
target_link_libraries(OmniServe 
  PRIVATE 
  Drogon::Drogon 
  gRPC::grpc++ 
  JsonCpp::JsonCpp
)

# --- Optionally enable testing ---
message(STATUS "Enabling testing...")
enable_testing()
add_subdirectory(tests)  # Uncomment if you have a tests folder

# --- Final message ---
message(STATUS "OmniServe project setup completed successfully!")
