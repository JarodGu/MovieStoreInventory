cmake_minimum_required(VERSION 3.13)
project(asg4)

set(CMAKE_CXX_STANDARD 11)

add_executable(asg4 driver.cpp store.h store.cpp bintree.h bintree.cpp nodedata.h nodedata.cpp)