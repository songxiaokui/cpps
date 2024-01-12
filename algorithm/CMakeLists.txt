cmake_minimum_required(VERSION 3.19)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        algorithm
        main.cpp
        src/structure/hashtable/hashtable.cpp
        src/structure/hashtable/hashtable.h
        src/structure/hashtable/hashtableplus.cpp src/structure/hashtable/hashtableplus.h src/structure/tree/tree.cpp src/structure/tree/tree.h src/structure/listtree/listtree.cpp src/structure/listtree/listtree.h)
