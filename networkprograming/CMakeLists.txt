cmake_minimum_required(VERSION 3.24)
# cmake_minimum_required 设置cmake的版本 并且要放在cmake文件的顶部分 本质是给该变量：CMAKE_MINIMUM_REQUIRED_VERSION 赋值

# 设置CMAKE_ROOT_PATH变量的路径在与CmakeLists.txt同级的cmake目录
set(CMAKE_ROOT_PATH ${CMAKE_SOURCE_DIR}/cmake)
# 设置CMAKE_MODULE_PATH变量 指定额外的Cmake模块查找路径 默认值为空
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_ROOT_PATH}/Modules/")
# 设置CMAKE_EXTERNAL_PATH 项目外部依赖的路径
set(CMAKE_EXTERNAL_PATH ${CMAKE_ROOT_PATH}/External)

# Make sure that all _ROOT variables *are* used when they are set.
# 设置策略 控制cmake行为
cmake_policy(SET CMP0000 NEW) # 保留策略
cmake_policy(SET CMP0022 OLD) # 控制链接器查找是否可以使用相对路径
cmake_policy(SET CMP0048 NEW) # 使用project()
if (POLICY CMP0074)
    # 控制链接对象的方式
    cmake_policy(SET CMP0074 NEW)
endif ()

# 指定为C++17 版本
set(CMAKE_CXX_STANDARD 17)

# 引入Utils.cmake文件 提供工程版本号信息功能
include(${CMAKE_ROOT_PATH}/Utils.cmake)
# 引入System.cmake 提供系统信息输出
include(${CMAKE_ROOT_PATH}/System.cmake)
# 引入SearchIncludeDir.cmake 设置可以搜索二级目录下的路径列表
include(${CMAKE_ROOT_PATH}/SearchIncludeDir.cmake)
# 引入MyLearn.cmake 用来学习cmake的基本语法
include(${CMAKE_ROOT_PATH}/MyLearn.cmake)

#--------------------------------------------
# Project setting
#--------------------------------------------
set(PROJECT_NAME "networkprograming")

# 引入cmake内置CMakeDependentOption库 使用option方法
include(CMakeDependentOption)
option(BUILD_THIRD_PARTY_MODE "Build ${PROJECT_NAME} Dependency Only." OFF)

if (BUILD_THIRD_PARTY_MODE)
    MESSAGE(STATUS "Build ${PROJECT_NAME} Dependency Only: ${BUILD_THIRD_PARTY_MODE}")
else ()
    PROJECT_EXTRACT_VERSION()
endif ()

PROJECT(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX)

MESSAGE(INFO "--------------------------------")
MESSAGE(STATUS "Build ${PROJECT_NAME}: ${PROJECT_VERSION}")
MESSAGE(STATUS "Found ${PROJECT_NAME} host system: ${HOST_SYSTEM}")
MESSAGE(STATUS "Found ${PROJECT_NAME} host system's CPU: ${CPU_CORES} cores")
#
# Project User options
# ============
# option(BUILD_WITH_VTK "Build ${PROJECT_NAME} with VTK dependency." OFF)
# option(BUILD_WITH_OPENCASCADE "Build ${PROJECT_NAME} with OpenCasCade dependency." ON)
# option(BUILD_WITH_MEDFILEIO "Build ${PROJECT_NAME} with MEDFileIO dependency." ON)
# option(BUILD_WITH_LIBZIP "Build ${PROJECT_NAME} with LibZip dependency." ON)
# option(BUILD_WITH_GMSH "Build ${PROJECT_NAME} with GMSH dependency." ON)
# option(BUILD_WITH_NUMCPP "Build ${PROJECT_NAME} with NumCpp dependency." OFF)
# option(BUILD_WITH_CLICKHOUSE "Build ${PROJECT_NAME} with ClickHouse dependency." OFF)
# option(BUILD_WITH_PARAVIEW "Build ${PROJECT_NAME} with ParaView dependency." ON)
# option(BUILD_WITH_BOOST "Build ${PROJECT_NAME} with Boost dependency." ON)

option(BUILD_WITH_FILE_EXAMPLES "Install examples ." OFF)
option(BUILD_TESTS "Build ${PROJECT_NAME} tests." ON)
option(BUILD_DOC "Build ${PROJECT_NAME} doc." OFF)

option(BUILD_WITH_STATIC "Build ${PROJECT_NAME} dependency library in static mode." OFF)
option(BUILD_WITH_PARALLEL "Build ${PROJECT_NAME} dependency library with parallel mode." OFF)

if (BUILD_WITH_STATIC)
    # set(BUILD_DEPS_SUFFIX "_static")
    set(BUILD_SHARED_LIBS FALSE)
    # set(BUILD_WITH_PARALLEL OFF)
else ()
    #set(BUILD_DEPS_SUFFIX "")
    set(BUILD_SHARED_LIBS TRUE)
endif ()

option(USE_LOCAL_THIRD_PARTY "Build ${PROJECT_NAME} with Local dependency." OFF)

if (${HOST_SYSTEM} STREQUAL "ubuntu")
    set(BUILD_AT_UBUNTU TRUE)
elseif (${HOST_SYSTEM} STREQUAL "centos")
    set(BUILD_AT_CENTOS TRUE)
elseif (${HOST_SYSTEM} STREQUAL "macosx")
    set(BUILD_AT_MACOSX TRUE)
else ()
    message(FATAL_ERROR "Sorry !! This Platform Is Not Currently Supported !")
endif ()

# CMAKE_BUILD_TYPE
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
            "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel"
            FORCE)
endif ()
MESSAGE(STATUS "${PROJECT_NAME} CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

# 判读在DEBUG模式下是否加入DEBUG宏
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_definitions(-DUSE_DEBUG)
else ()
    # add_definitions(-DUSE_TEST)
endif ()

# todo 官方文档提示慎用此功能 故在此做标记（用于获取所有需要包含的编译文件）
# 递归获取目标路径下的所有需要编译的文件
set(SRC_SOURCES "")
file(GLOB_RECURSE SRC_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*cxx)

file(GLOB_RECURSE HEAD_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*hxx)

# foreach(file ${SRC_SOURCES})
#     message(STATUS "add src file = ${file}")
# endforeach()

# foreach(file ${HEAD_SOURCES})
#     message(STATUS "add head file = ${file}")
# endforeach()

# 向下递归二级获取目标路径下的所有需要包含的头文件夹
set(SOURCE_INCLUDE_DIRS "")
FIND_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src SOURCE_INCLUDE_DIRS)

add_executable(${PROJECT_NAME} src/hvserver.cpp src/hvserver.h)

# SET THIRD_PARTY_PATH
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})
set(THIRD_PARTY_PATH "${PROJECT_ROOT}/third_party" CACHE STRING
        "A path setting third party libraries download & build directories.")

# These lists are later turned into target properties on main ${PROJECT_NAME} library target
set(PROJECT_INCLUDE_DIRS "")
set(PROJECT_LINKER_LIBS "")
set(PROJECT_LINKER_DIRS "")
set(PROJECT_EXTERNAL_DEPENDENCIES "")

# DOWNLOAD BUILD INSTALL THIRD_PARTY_PATH
include(${CMAKE_ROOT_PATH}/Dependencies.cmake)

if (PROJECT_EXTERNAL_DEPENDENCIES)
    add_dependencies(${PROJECT_NAME} ${PROJECT_EXTERNAL_DEPENDENCIES})
endif ()

target_sources(${PROJECT_NAME}
        PUBLIC ${HEAD_SOURCES}
        PRIVATE ${SRC_SOURCES}
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${SOURCE_INCLUDE_DIRS})

if (BUILD_THIRD_PARTY_MODE)
    MESSAGE(STATUS "Not Link Everything")
else ()
    include_directories(${PROJECT_NAME}
            PUBLIC
            ${PROJECT_INCLUDE_DIRS}
            )

    if (BUILD_WITH_STATIC)
        target_link_libraries(${PROJECT_NAME}
                PUBLIC
                -Wl,--start-group
                ${PROJECT_LINKER_LIBS}
                -Wl,--end-group
                )
    else ()
        # use, i.e. don't skip the full RPATH for the build tree
        set(CMAKE_SKIP_BUILD_RPATH FALSE)

        # when building, don't use the install RPATH already
        # (but later on when installing)
        set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

        # the RPATH to be used when installing
        set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib" "${PROJECT_LINKER_DIRS}")

        # add the automatically determined parts of the RPATH
        # which point to directories outside the build tree to the install RPATH
        set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

        target_link_directories(${PROJECT_NAME}
                PUBLIC
                ${PROJECT_LINKER_DIRS})

        target_link_libraries(${PROJECT_NAME}
                PUBLIC
                ${PROJECT_LINKER_LIBS})
    endif ()
endif ()

# foreach (lib ${PROJECT_LINKER_LIBS})
#     message(STATUS "link lib = ${lib}")
# endforeach ()
#
# foreach (dir ${PROJECT_INCLUDE_DIRS})
#     message(STATUS "link include dir = ${dir}")
# endforeach ()


