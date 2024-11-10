# Unit tests
add_executable(test_main test_main.cpp)
target_link_libraries(test_main PRIVATE Qt5::Core Qt5::Network drogon gRPC::grpc++)
add_test(NAME test_main COMMAND test_main)
