cmake_minimum_required(VERSION 3.24)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        algorithm
        main.cpp
        src/structure/hashtable/hashtable.cpp
        src/structure/hashtable/hashtable.h
)
