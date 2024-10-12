# Set the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(FirstGame VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories for header files
include_directories(include)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Automatically collect all source and header files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Add the executable
add_executable(FirstGame ${SOURCES} ${HEADERS}
        include/terrain.h
        src/terrain.cpp)

# Link SFML libraries
target_link_libraries(FirstGame sfml-graphics sfml-window sfml-system)