cmake_minimum_required(VERSION 3.5)
project(homeworks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Cart/main.cpp Cart/cart.cpp Cart/cart.h Cart/cart_list.cpp Cart/cart_list.h)
add_executable(homeworks ${SOURCE_FILES})