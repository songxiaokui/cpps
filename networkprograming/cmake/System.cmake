# Copyright (c) 2016 PaddlePaddle Authors. All Rights Reserve.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Detects the OS and sets appropriate variables.
# CMAKE_SYSTEM_NAME only give us a coarse-grained name,
# but the name like centos is necessary in some scenes
# to distinguish system for customization.
#
# for instance, protobuf libs path is <install_dir>/lib64
# on CentOS, but <install_dir>/lib on other systems.

IF(WIN32)
    SET(HOST_SYSTEM "win32")
ELSE(WIN32)
    IF(APPLE)
        # EXEC_PROGRAM 用来执行外部程序的命令
        # sw_vers 外部程序 用来查看软件版本信息的命令
        # ARGS 用来设置sw_vers的参数
        # -productVersion 传递给sw_vers参数 输出操作系统的版本号
        # OUTPUT_VARIABLE 输出控制选项 将输出结果指定到变量MACOSX_VERSION中
        EXEC_PROGRAM (sw_vers ARGS -productVersion OUTPUT_VARIABLE MACOSX_VERSION)
        # STRING 字符串操作命令
        # REGEX MATCH 正则匹配
        # 将MACOSX_VERSION变量的值 进行正则匹配数字 存储在变量VERSION变量中
        STRING(REGEX MATCH "[0-9]+.[0-9]+" VERSION "${MACOSX_VERSION}")
        # 设置macos系统的版本号
        SET(MACOS_VERSION ${VERSION})
        # 设置主机系统为 macosx
        SET(HOST_SYSTEM "macosx")
    ELSE(APPLE)

        IF(EXISTS "/etc/issue")
            FILE(READ "/etc/issue" LINUX_ISSUE)
            IF(LINUX_ISSUE MATCHES "CentOS")
                SET(HOST_SYSTEM "centos")
            ELSEIF(LINUX_ISSUE MATCHES "Debian")
                SET(HOST_SYSTEM "debian")
            ELSEIF(LINUX_ISSUE MATCHES "Ubuntu")
                SET(HOST_SYSTEM "ubuntu")
            ELSEIF(LINUX_ISSUE MATCHES "Red Hat")
                SET(HOST_SYSTEM "redhat")
            ELSEIF(LINUX_ISSUE MATCHES "Fedora")
                SET(HOST_SYSTEM "fedora")
            ENDIF()
        ENDIF(EXISTS "/etc/issue")

        IF(EXISTS "/etc/redhat-release")
            FILE(READ "/etc/redhat-release" LINUX_ISSUE)
            IF(LINUX_ISSUE MATCHES "CentOS")
                SET(HOST_SYSTEM "centos")
            ENDIF()
        ENDIF(EXISTS "/etc/redhat-release")

        IF(NOT HOST_SYSTEM)
            SET(HOST_SYSTEM ${CMAKE_SYSTEM_NAME})
        ENDIF()

    ENDIF(APPLE)
ENDIF(WIN32)

# query number of logical cores
# CMAKE_HOST_SYSTEM_INFORMATION 查询主机的信息并存放在变量CPU_CORES中
# NUMBER_OF_LOGICAL_CORES 表示获取主机逻辑CPU数量
CMAKE_HOST_SYSTEM_INFORMATION(RESULT CPU_CORES QUERY NUMBER_OF_LOGICAL_CORES)

# 将变量HOST_SYSTEM CPU_CORES 标记为系统高级选项
# 在Cmake GUI中不会默认显示 但是不会影响Cmake文件对该变量的访问
# 只要被标记为高级选项 无论那个Cmake文件 都可以通过${变量名进行访问}
MARK_AS_ADVANCED(HOST_SYSTEM CPU_CORES)

# external dependencies log output
# 定义了一个键值对变量 EXTERNAL_PROJECT_LOG_ARGS 用来配置外部项目的日志输出选项
# EXTERNAL_PROJECT_LOG_ARGS 将该对象解引用 就会展开
# 该函数主要是给 ExternalProject_Add 进行日志配置
# 会展开6项 分别设置
# LOG_DOWNLOAD 开启 将下载日志记录到日志文件中输出
# LOG_UPDATE 开启 将更新日志记录到文件中输出
# LOG_CONFIGURE 开启 配置步骤的输出记录到文件中
# LOG_BUILD 构建步骤的日志信息将输出到文件中
# LOG_TEST 开启 将测试的日志输出到文件中
# LOG_INSTALL 开启 将安装的日志输出到文件中
SET(EXTERNAL_PROJECT_LOG_ARGS
    LOG_DOWNLOAD    0     # Wrap download in script to log output
    LOG_UPDATE      1     # Wrap update in script to log output
    LOG_CONFIGURE   1     # Wrap configure in script to log output
    LOG_BUILD       0     # Wrap build in script to log output
    LOG_TEST        1     # Wrap test in script to log output
    LOG_INSTALL     0     # Wrap install in script to log output
)
