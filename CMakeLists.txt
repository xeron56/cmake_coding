cmake_minimum_required(VERSION 3.16)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the Boost package
find_package(Boost REQUIRED filesystem)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIRS})

# Add the executable
add_executable(MyProject src/main.cpp)

# Link against Boost libraries
target_link_libraries(MyProject ${Boost_LIBRARIES})