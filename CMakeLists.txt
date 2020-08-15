cmake_minimum_required(VERSION 3.17)
project(linq)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(range-v3)
include_directories(range-v3/include/)

add_executable(linq main.cpp iter.hpp)