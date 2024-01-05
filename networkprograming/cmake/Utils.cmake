# 在cmake中定义了一个没有参数的函数
FUNCTION(PROJECT_EXTRACT_VERSION)
    # CMAKE_CURRENT_LIST_DIR cmake内置变量 代表当前处理的 CMakeLists.txt 文件所在的目录
    # FILE READ 读取源文件中的cpp文件 将内容赋值给file_contents
    FILE(READ "${CMAKE_CURRENT_LIST_DIR}/src/common/version.hpp" file_contents)

    # 字符串 正则匹配主版本号
    # 如果匹配成功 CMAKE_MATCH_COUNT 变量会被设置1
    STRING(REGEX MATCH "PROJECT_VER_MAJOR ([0-9]+)" _  "${file_contents}")
    IF(NOT CMAKE_MATCH_COUNT EQUAL 1)
        # 如果没匹配到 则FATAL_ERROR中断执行
        MESSAGE(FATAL_ERROR "Could not extract major version number from version.hpp")
    ENDIF()
    # 如果匹配成功 会将匹配成功的分组信息保存在: CMAKE_MATCH_1 CMAKE_MATCH_2 CMAKE_MATCH_3 等变量中
    # 将主版本号保存在 ver_major
    SET(ver_major ${CMAKE_MATCH_1})

    # 正则匹配次版本号
    STRING(REGEX MATCH "PROJECT_VER_MINOR ([0-9]+)" _  "${file_contents}")
    IF(NOT CMAKE_MATCH_COUNT EQUAL 1)
        MESSAGE(FATAL_ERROR "Could not extract minor version number from version.hpp")
    ENDIF()
    # 将次版本号存放在 ver_minor
    SET(ver_minor ${CMAKE_MATCH_1})
    # 正则匹配补丁号 不保存匹配的内容
    STRING(REGEX MATCH "PROJECT_VER_PATCH ([0-9]+)" _  "${file_contents}")
    IF(NOT CMAKE_MATCH_COUNT EQUAL 1)
        MESSAGE(FATAL_ERROR "Could not extract patch version number from version.hpp")
    ENDIF()
    # 将补丁号保存在变量 ver_patch
    SET(ver_patch ${CMAKE_MATCH_1})
    # 定义变量PROJECT_VERSION_MAJOR 并设置该变量的外部链接性
    # PARENT_SCOPE 在函数外部的作用域中使用这些变量
    SET(PROJECT_VERSION_MAJOR ${ver_major} PARENT_SCOPE)
    # 定义项目版本变量 PROJECT_VERSION 并设置全局可见性
    SET(PROJECT_VERSION "${ver_major}.${ver_minor}.${ver_patch}" PARENT_SCOPE)
ENDFUNCTION()
