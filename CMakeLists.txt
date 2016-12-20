cmake_minimum_required(VERSION 3.5)
project(homeworks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp figures.h figures.cpp)
add_executable(homeworks ${SOURCE_FILES})