cmake_minimum_required(VERSION 3.15)
project(example)

set(CMAKE_CXX_STANDARD 14)
# The line below is necessary if you are under Windows only
# Comment the line below if you are under Linux or Mac OS

include_directories(src/GraphViewer)
include_directories(files)
file(GLOB_RECURSE SOURCE_FILES "src/*/*.cpp")

add_executable(cal ${SOURCE_FILES} src/main.cpp src/Emirita/HealthCare.cpp src/Emirita/HealthCare.h)
