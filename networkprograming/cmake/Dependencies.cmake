set(CompileCPUMax_MakeCommand make -j${CPU_CORES})

if (BUILD_WITH_STATIC)
    set(LIBRARY_PREFIX ${CMAKE_STATIC_LIBRARY_PREFIX})
    set(LIBRARY_SUFFIX ${CMAKE_STATIC_LIBRARY_SUFFIX})
else ()
    set(LIBRARY_PREFIX ${CMAKE_SHARED_LIBRARY_PREFIX})
    set(LIBRARY_SUFFIX ${CMAKE_SHARED_LIBRARY_SUFFIX})
endif ()

# ---[ Threads
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
list(APPEND PROJECT_LINKER_LIBS ${CMAKE_THREAD_LIBS_INIT})

# ---[ Event
set(EVENT_DirName "Event")
include(${CMAKE_EXTERNAL_PATH}/Event.cmake)
list(APPEND PROJECT_INCLUDE_DIRS ${EVENT_INCLUDE_DIRS})
list(APPEND PROJECT_LINKER_LIBS ${EVENT_LIBRARIES})

# --[ hv
set(Hv_DirName "Hv")  # 引入需要拓展的模块保存路径
include(${CMAKE_EXTERNAL_PATH}/Hv.cmake)  # 引入需要编译 hv 模块的 cmake 文件
# 将 hv 头文件所在的目录添加到项目的头文件查找路径中
list(APPEND PROJECT_INCLUDE_DIRS ${Hv_INCLUDE_DIRS})
# 将 hv 链接对象所在的路径添加到项目的链接查找路径中
list(APPEND PROJECT_LINKER_LIBS ${Hv_LIBRARIES})
# 所以 关键目的就是获取 Hv_INCLUDE_DIRS  Hv_LIBRARIES 这两个变量