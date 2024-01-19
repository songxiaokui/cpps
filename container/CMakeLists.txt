cmake_minimum_required(VERSION 3.24)
project(container)

set(CMAKE_CXX_STANDARD 17)

add_executable(file main.cpp src/container/mylist.cpp src/container/mylist.h src/container/queue.cpp src/container/queue.h src/container/stack.cpp src/container/stack.h src/container/map.cpp src/container/map.h src/container/priority_queue.cpp src/container/priority_queue.h src/template/function.cpp src/template/function.h)
