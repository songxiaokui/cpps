cmake_minimum_required(VERSION 3.19)
project(container CXX C)

# 设置标准
set(CMAKE_CXX_STANDARD 17)
set(SEARCH_FILE_PATH ${PROJECT_SOURCE_DIR}/src)
# 查找源文件
file(GLOB_RECURSE SOURCE_FILES ${SEARCH_FILE_PATH}/*.cpp)

# 查找头文件(递归查询)
file(GLOB_RECURSE HEADER_FILES ${SEARCH_FILE_PATH}/*.h)

# 获取所有的头文件目录
get_filename_component(HEADER_DIRS "${HEADER_FILES}" DIRECTORY)
list(REMOVE_DUPLICATES HEADER_DIRS)

add_executable(container main.cpp ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(container PRIVATE ${HEADER_DIRS})
