cmake_minimum_required(VERSION 3.16)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(MyProject src/main.cpp)