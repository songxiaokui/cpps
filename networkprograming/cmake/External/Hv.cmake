if(NOT __Hv_INCLUDE)
    # 如果没有设置__Hv_INCLUDE 则编译安装
    set(__Hv_INCLUDE TRUE)
    # 设置源代码路径
    set(Hv_SOURCES_DIR ${THIRD_PARTY_PATH}/${Hv_DirName}/${Hv_DirName}-sources)
    # 设置安装路径
    set(Hv_INSTALL_DIR ${THIRD_PARTY_PATH}/${Hv_DirName}/${Hv_DirName}-install)

    # 设置 Hv 的安装路径 在查找时会使用该参数
    # FindHv.cmake Hv_ROOT_DIR find_package
    set(Hv_ROOT_DIR ${Hv_INSTALL_DIR})
    # 设置查找库的路径 格式为(库名_DIR 编译好的库的路径)
    # 该名称一定要对 只能在编译成功后 获取到
    # TODO 设置查找库的路径(注意: 库名为 libhv)
    set(libhv_DIR ${Hv_ROOT_DIR}/lib/cmake/libhv)
    message("LibHV 编译后的地址为：${libhv_DIR}")
    # 包名为 cmake文件的前缀名称 会自动去 拓展模块CMAKE_EXTERNAL_PATH目录下去找 FindHv.cmake
    find_package(Hv)

    # 如果没找到 就开始进行安装
    if (NOT Hv_FOUND)
        # 编译安装
        # 设置文件路径 可以从网上下载 也可以本地路径
        set(Hv_URL file://${THIRD_PARTY_PATH}/libhv-1.3.2.zip)

        # 允许使用外部拓展模块
        include(ExternalProject)
        # 添加一个外部项目
        ExternalProject_Add(
                # 模块名称
                ${Hv_DirName}
                # 外部项目安装目录的前缀
                PREFIX ${Hv_SOURCES_DIR}
                # URL 外部项目的源代码地址
                URL ${Hv_URL}
                # 是否构建共享库 BUILD_SHARED_LIBS=False 默认不构建共享
                CMAKE_ARGS -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}
                # 是否构建案例
                CMAKE_ARGS -DBUILD_EXAMPLES=OFF
                # 构建的类型 release 还是 debug
                CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                # 安装路径
                CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${Hv_INSTALL_DIR}
                # 构建命令
                BUILD_COMMAND make -j
                # 安装路径
                INSTALL_DIR ${Hv_INSTALL_DIR}
                # 日志配置 解压 map
                ${EXTERNAL_PROJECT_LOG_ARGS}
        )
        # 获取安装的路径 设置为库的安装路径
        ExternalProject_Get_Property(${Hv_DirName} INSTALL_DIR)

        set(Hv_INCLUDE_DIRS ${INSTALL_DIR}/include)
        # 更新为库名
        set(Hv_LIB_NAME "libhv")
        set(Hv_LIBRARIES ${INSTALL_DIR}/lib/${LIBRARY_PREFIX}${Hv_LIB_NAME}${LIBRARY_SUFFIX})

        list(APPEND PROJECT_EXTERNAL_DEPENDENCIES ${Hv_DirName})
    endif()

endif()