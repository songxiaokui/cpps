# cmake 单行注释
#[[
    cmake 多行注释1
    cmake 多行注释2
 ]]
cmake_minimum_required(VERSION 3.19)
project(
        container
        VERSION 1.0.0
        DESCRIPTION "容器相关的使用案例"
        HOMEPAGE_URL "https://www.austsxk.com"
        LANGUAGES CXX C
)

# 定义变量
set(NAME "sxk")
message("NAME is" ${NAME})
# set(NAME)
unset(NAME)
message("NAME is" ${NAME})

# 设置标准
set(CMAKE_CXX_STANDARD 17)
# 定义环境变量
message("当前路径: " $ENV{PWD})
set(ENV{MYPWD} "/usr/local")
message("当前路径: " $ENV{MYPWD})

# 设置缓存
set(CACHE_ME ON CACHE BOOL "是否缓存" FORCE)
message("缓存设置: " ${CACHE_ME})
if (CACHE_ME)
    message("已设置缓存")
endif()

# 宏设置 设置可执行程序的输出路径
set(EXECUTABLE_OUTPUT_PATH $ENV{PWD})

# 使用 aux_source_directory 搜索文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SEARCH_LISTS)
message("aux_source_directory 搜索根路径下的源文件为: " ${SEARCH_LISTS})

set(SEARCH_FILE_PATH ${PROJECT_SOURCE_DIR}/src)
# 查找源文件
file(
        GLOB_RECURSE
        SOURCE_FILES
        ${SEARCH_FILE_PATH}/*.cpp
        ${SEARCH_FILE_PATH}/*.cxx
)

# 查找头文件(递归查询)
file(GLOB_RECURSE HEADER_FILES ${SEARCH_FILE_PATH}/*.h)

# 获取所有的头文件目录
get_filename_component(HEADER_DIRS "${HEADER_FILES}" DIRECTORY)
list(REMOVE_DUPLICATES HEADER_DIRS)

add_executable(container main.cpp ${SOURCE_FILES} ${HEADER_FILES} src/template/listnode.cpp src/template/listnode.h src/problem/leetcode_stack.cpp)

target_include_directories(container PRIVATE ${HEADER_DIRS})
