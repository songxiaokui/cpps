cmake_minimum_required(VERSION 3.19)
project(memoryModelAndNamespace LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(memoryModelAndNamespace main.cpp main.h src/memoryModelAndNamespace/compiler/compiler.cpp src/memoryModelAndNamespace/compiler/compiler.h src/memoryModelAndNamespace/namespace/namespace.cpp src/memoryModelAndNamespace/namespace/namespace.h src/memoryModelAndNamespace/compiler/hide.cpp src/memoryModelAndNamespace/compiler/hide.h src/memoryModelAndNamespace/compiler/inner_static.cpp src/memoryModelAndNamespace/compiler/inner_static.h src/memoryModelAndNamespace/compiler/mymutable.h src/memoryModelAndNamespace/compiler/mymutable.cpp src/memoryModelAndNamespace/compiler/myconst.cpp src/memoryModelAndNamespace/compiler/myconst.h src/memoryModelAndNamespace/compiler/functionlink.cpp src/memoryModelAndNamespace/compiler/functionlink.h src/memoryModelAndNamespace/compiler/language_link.c src/memoryModelAndNamespace/compiler/language_link.h)
