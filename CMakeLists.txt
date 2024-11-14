cmake_minimum_required(VERSION 3.15)

# تعریف پروژه
project(OmniServe VERSION 1.0 LANGUAGES CXX)

# تنظیم استاندارد C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# استفاده از فایل ابزار vcpkg برای مدیریت وابستگی‌ها
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "/projects/libarary/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
endif()

# تنظیم CMAKE_PREFIX_PATH برای کمک به پیدا کردن کتابخانه‌ها در vcpkg
set(CMAKE_PREFIX_PATH "/projects/libarary/vcpkg/installed/x64-linux" ${CMAKE_PREFIX_PATH})

# شروع پیکربندی پروژه
message(STATUS "Starting project configuration...")

# فعال‌سازی خروجی verbose برای اشکال‌زدایی بهتر
set(CMAKE_VERBOSE_MAKEFILE ON)

# پیدا کردن پکیج‌ها و کتابخانه‌های مورد نیاز
find_package(Drogon CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)

# پیدا کردن کتابخانه UUID
find_library(UUID_LIB NAMES uuid REQUIRED PATHS /usr/lib/x86_64-linux-gnu)

if (UUID_LIB)
  message(STATUS "UUID library found at: ${UUID_LIB}")
else()
  message(FATAL_ERROR "UUID library not found. Make sure it is installed and available.")
endif()

# ایجاد فایل اجرایی اصلی
add_executable(OmniServe src/main.cpp)

# تنظیم کتابخانه‌های مورد نیاز برای لینک‌دهی
target_link_libraries(OmniServe 
  PRIVATE 
  Drogon::Drogon
  gRPC::grpc 
  gRPC::grpc++ 
  protobuf::libprotobuf       # استفاده از libprotobuf به عنوان هدف
  protobuf::libprotoc         # استفاده از libprotoc برای پروتوباف
  JsonCpp::JsonCpp 
  ${UUID_LIB}
)

# پیام نهایی
message(STATUS "OmniServe project setup completed successfully!")
