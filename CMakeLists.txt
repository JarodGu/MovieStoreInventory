cmake_minimum_required(VERSION 3.9)
project(Cropley___Assignment_4)

set(CMAKE_CXX_STANDARD 11)

add_executable(Cropley___Assignment_4 driver.cpp classic.h classic.cpp comedy.h
        comedy.cpp drama.h drama.cpp media.h media.cpp movie.h movie.cpp
        bintree.h bintree.cpp nodedata.h nodedata.cpp customer.h customer.cpp
        customertable.h customertable.cpp store.h store.cpp)