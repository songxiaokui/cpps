# - Find Hv
# 查找 Hv 库的头文件和链接对象文件
# Hv_INCLUDE_DIRS 头文件存储路径
# Hv_LIBRARIES 库文件对象存储路径
# Hv_FOUND 是查找 Hv 后自动生成的变量 如果为真 则找到该库 否则 没找到该库
# Hv_ROOT_DIR hv 库的安装目录 在 安装第三方库路径下设置

# 查找头文件是否存在
find_path(
        Hv_INCLUDE_DIR
        NAMES hv.h
        HINTS ${Hv_ROOT_DIR}/include/hv
        NO_DEFAULT_PATH
)

# 查找库文件是否存在
find_library(
        Hv_LIBRARY
        NAMES hv
        HINTS ${Hv_ROOT_DIR}/lib
        NO_DEFAULT_PATH
)

# 判断是否存在头文件 并且头文件存在 从头文件中获取一些版本信息等
if (Hv_INCLUDE_DIR AND EXISTS "${Hv_INCLUDE_DIR}/hv.h")
    message("LibHv is exists...")
endif()

# 在 cmake 中引入FindPackageHandleStandardArgs 宏定义
# 可以提供一个标准的处理查找结果的方法 从而确保找到包活没有包的一致性处理
# 配合find_package_handle_standard_args 进行处理
# 会产生一个结果 包名_FOUND变量
# 如果为真 则找到包 否则 找不到
find_package_handle_standard_args(Hv REQUIRED_VARS Hv_LIBRARY Hv_INCLUDE_DIR)

# 处理查找包的情况
if (Hv_FOUND)
    # 找到包后 主要就是把两个路径设置上
    # Hv_INCLUDE_DIRS 头文件存储路径
    # Hv_LIBRARIES 库文件对象存储路径

    # 如果不是 cmake 项目 直接使用系统命令安装
    # 则直接进行赋值即可 通常这些文件在系统 /usr/lib /usr/include 等路径下

    # 如果是 cmake 项目
    # 此时第一次编译会找不到链接对象
    # 需要找到编译后的 cmake config 文件 查询这两个路径
    # 同时 确认编译后的包名

    # TODO 此处替换库名 (编译成功后: libhvConfig.cmake)
    # 注意: 由于此处没有对外暴露变量 我们直接使用安装路径下进行匹配库文件和头文件
    find_package(libhv NO_MODULE)
    # TODO 查找最后的路径
    set(Hv_LIBRARIES ${Hv_INSTALL_DIR}/lib/libhv.dylib)  # TODO 如何不写死 需要解决
    # TODO 查找最后的路径
    set(Hv_INCLUDE_DIRS ${Hv_INSTALL_DIR}/include/hv)
    # 将变量设置为全局可见
    mark_as_advanced(Hv_LIBRARIES Hv_INCLUDE_DIRS)
endif()