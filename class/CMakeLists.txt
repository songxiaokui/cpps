cmake_minimum_required(VERSION 3.19)
project(class LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
add_executable(class main.cpp main.h src/base/circle.cpp src/base/circle.h src/limits/limits.cpp src/limits/limits.h src/base/cube.cpp src/base/cube.h src/functions/func.cpp src/functions/func.h src/reference/reference.cpp src/reference/reference.h src/build/classbuildfuntion.cpp src/build/classbuildfuntion.h src/thispointer/thispointer.cpp src/thispointer/thispointer.h src/reloadoperator/reloadoperator.cpp src/reloadoperator/reloadoperator.h src/reloadoperator/leftmove.cpp src/reloadoperator/leftmove.h)