cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# define the CMake project
project(hello
    VERSION 0.0.0
    DESCRIPTION "Example project supporting both a system installable CMake project and a pip-installable pybind11 wrapper"
    LANGUAGES CXX)

# defines useful variables for installation subdirectories per GNU standards
include(GNUInstallDirs)

# define the hello library
add_library(${PROJECT_NAME} SHARED)

# add source files to the hello library
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/hello.cpp)

# add include directories for the hello library
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

# install hello library shared object
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}")

# install hello library headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
