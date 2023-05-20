cmake_minimum_required(VERSION 3.23)
project(IVFS)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(IVFS src/main.cpp include/ivfs.h include/file.h src/ivfs.cpp src/file.cpp)
