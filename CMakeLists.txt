cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# define the CMake project
project(hello
    VERSION 0.0.0
    DESCRIPTION "Example project supporting both a system installable CMake project and a pip-installable pybind11 wrapper"
    LANGUAGES CXX)

# defines useful variables for installation subdirectories per GNU standards
include(GNUInstallDirs)

# defines functions for creating config cmake files
include(CMakePackageConfigHelpers)

# define the hello library
add_library(${PROJECT_NAME} SHARED)

# add source files to the hello library
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/hello.cpp)

# add include directories for the hello library
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# install hello library shared object
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets                   # associates target with an export object
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}")

# install hello library headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

# writes a cmake file to the build directory containing this project's targets,
# so this project can be used as a sub-project
export(
    TARGETS ${PROJECT_NAME}
    NAMESPACE ${PROJECT_NAME}::
    FILE ${PROJECT_NAME}Targets.cmake)

# installs the export object to the system,
# so other project may import the targets from this project using find_package
install(
    EXPORT ${PROJECT_NAME}Targets
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake")

# write out basic version config file
# this file is used by `find_package` to check if the version of the package meats
# the version requirement of the consuming project
write_basic_package_version_file(${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMinorVersion)

# write out package config file to the binary_dir
# this file allows a consuming CMake to import this package `find_package`
# the config file should setup the consuming project to be able to use the exported targets
configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION
  "${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake")

# install the generated config and version files to the system
install(
    FILES
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake")
