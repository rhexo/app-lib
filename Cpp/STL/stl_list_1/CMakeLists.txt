# Specify the minimum version of Cmake
cmake_minimum_required(VERSION 2.8)

# Project`s name
project(hello)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Compile with C++11 support
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# The folowing folder will be included
include_directories("${PROJECT_SOURCE_DIR}/include")

#file(GLOB SOURCES "*.cpp")

# Create application executable
add_executable(hello
  include/printer.h
  printer.cpp

  main.cpp)
