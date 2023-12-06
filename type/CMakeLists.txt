cmake_minimum_required(VERSION 3.19)
project(type LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
file(GLOB SRC_FILES "${CMAKE_CURRENT_LIST_DIR}/src/helloworld/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/src/helloworld/*.h*")

add_executable(type main.cpp ${SRC_FILES} src/tint/cint.cpp src/tint/cint.h src/string/mystring.cpp src/string/mystring.h src/float/myfloat.cpp src/float/myfloat.h src/mstruct/mystruct.cpp src/mstruct/mystruct.h src/branch/branch.cpp src/branch/branch.h)