cmake_minimum_required(VERSION 3.13)
project(asg4)

set(CMAKE_CXX_STANDARD 11)

add_executable(asg4 driver.cpp store.h store.cpp bintree.h bintree.cpp nodedata.h nodedata.cpp
        classic.h classic.cpp comedy.h comedy.cpp customer.h customer.cpp customertable.h customertable.cpp
        drama.h drama.cpp media.h media.cpp movie.h movie.cpp)