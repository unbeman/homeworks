cmake_minimum_required(VERSION 3.5)
project(homeworks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Cart/bin_cart.cpp Cart/cart.cpp Cart/cart.h Cart/cart_list.cpp Cart/cart_list.h Animal/bin_animal.cpp Computer/bin_computer.cpp Figures/bin_figures.cpp)
add_executable(homeworks ${SOURCE_FILES})