cmake_minimum_required(VERSION 3.16)
project(calProj)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(cute_lib)

file(GLOB_RECURSE SOURCE_FILES "src/*/*.cpp")

add_executable(calProj ${SOURCE_FILES})
