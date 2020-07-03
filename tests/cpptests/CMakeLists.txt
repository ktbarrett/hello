cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(test_installed_hello VERSION 0.0.0 LANGUAGES CXX)

include(FetchContent)

find_package(hello 0.0.0 REQUIRED)

FetchContent_Declare(catch
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.12.3)
FetchContent_MakeAvailable(catch)

add_executable(test_app main.cpp tests.cpp)
target_link_libraries(test_app PRIVATE Catch2::Catch2 hello::hello)
