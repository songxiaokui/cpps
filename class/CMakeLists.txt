cmake_minimum_required(VERSION 3.19)
project(class LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
add_executable(class main.cpp main.h src/base/circle.cpp src/base/circle.h src/limits/limits.cpp src/limits/limits.h)