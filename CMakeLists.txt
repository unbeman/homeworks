cmake_minimum_required(VERSION 3.5)
project(homeworks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES Cart/bin_cart.cpp Cart/cart.cpp Cart/cart.h Cart/cart_list.cpp Cart/cart_list.h Animal/bin_animal.cpp Computer/bin_computer.cpp Figures/bin_figures.cpp)
#add_executable(homeworks ${SOURCE_FILES})
add_executable(animal Animal/bin_animal.cpp Animal/animal.cpp Animal/animal.h)
add_executable(cart Cart/bin_cart.cpp Cart/cart.h Cart/cart.cpp Cart/cart_list.h Cart/cart_list.cpp Cart/std_list.h)
add_executable(computer Computer/bin_computer.cpp Computer/computer.cpp Computer/computer.h)
add_executable(figures Figures/bin_figures.cpp Figures/figures.cpp Figures/figures.h)
add_executable(stack Stack/bin_stack.cpp Stack/Stack.cpp Stack/Stack.h)