# - Find Event
# Find the Event includes and library
# EVENT_ROOT_DIR - ROOT of zlib library
# EVENT_INCLUDE_DIRS - where to find event.h
# EVENT_LIBRARIES - List of libraries when using event.
# Event_FOUND - True if event found.

# find_path是用来查找某个文件的路径
# 该处的意思是 在EVENT_ROOT_DIR event 的安装路径下的 include 目录下查找 event.h文件
# 如果文件存在 就把路径存储在EVENT_INCLUDE_DIR变量中 并且变量不设置默认值
find_path(EVENT_INCLUDE_DIR
        NAMES event.h
        HINTS ${EVENT_ROOT_DIR}/include
        NO_DEFAULT_PATH)

# find_library 用来查找库文件 在指定的目录下去查找 库文件
# linux: lib名称.so macos: lib名称.dylib
# 如果查找到该库 就将路径赋值给 EVENT_LIBRARY
find_library(EVENT_LIBRARY
        NAMES event
        HINTS ${EVENT_ROOT_DIR}/lib
        NO_DEFAULT_PATH)

# 如果系统已经存在该库文件
if(EVENT_INCLUDE_DIR AND EXISTS "${EVENT_INCLUDE_DIR}/event.h")
    # 解析文件获取主、次等版本号
    # 设置版本号信息变量
    message("event has exists.")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Event REQUIRED_VARS EVENT_LIBRARY EVENT_INCLUDE_DIR)

if (Event_FOUND)
    # 这个操作必须是在安装后进行补充
    # 从安装后的库 LibeventConfig.cmake中获取
    # link object: event

    # 使用
    #  LIBEVENT_FOUND            - true if libevent and all required components found on the system
    #  LIBEVENT_xxx_FOUND        - true if component xxx(see available components) found on the system
    #  LIBEVENT_VERSION          - libevent version in format Major.Minor.Patch
    #  LIBEVENT_INCLUDE_DIRS     - directories where libevent header is located.
    #  LIBEVENT_INCLUDE_DIR      - same as DIRS
    #  LIBEVENT_LIBRARIES        - libevent library to link against.
    #  LIBEVENT_LIBRARY          - same as LIBRARIES

    # 去掉Config前部分为target
    find_package(Libevent NO_MODULE)

    set(EVENT_LIBRARIES ${LIBEVENT_LIBRARIES})
    set(EVENT_INCLUDE_DIRS ${LIBEVENT_INCLUDE_DIRS})
    mark_as_advanced(EVENT_INCLUDE_DIRS EVENT_LIBRARIES)
ENDIF ()
