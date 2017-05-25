cmake_minimum_required(VERSION 3.7)
project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

include(CMakeToolsHelpers OPTIONAL)
set(SOURCE_FILES longest_harmonous_subsequence.cpp)
add_executable(Leetcode ${SOURCE_FILES})