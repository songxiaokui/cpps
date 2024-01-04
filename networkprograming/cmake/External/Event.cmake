if (NOT __EVENT_INCLUDED)
    set(__EVENT_INCLUDED TRUE)

    # Event build directory
    set(EVENT_SOURCES_DIR ${THIRD_PARTY_PATH}/${EVENT_DirName}/${EVENT_DirName}-sources)
    # Event install directory
    set(EVENT_INSTALL_DIR ${THIRD_PARTY_PATH}/${EVENT_DirName}/${EVENT_DirName}-install)

    # where to find Freetype
    set(EVENT_ROOT_DIR ${EVENT_INSTALL_DIR})
    set(Libevent_DIR ${EVENT_ROOT_DIR}/lib/cmake/libevent)
    message("----${event_DIR}--")
    find_package(Event)

    if (NOT Event_FOUND)
        set(EVENT_URL "")
        if (NOT USE_LOCAL_THIRD_PARTY)
            set(EVENT_URL "https://github.com/libevent/libevent/archive/refs/tags/release-2.1.12-stable.zip")
        else ()
            set(EVENT_URL file://${THIRD_PARTY_PATH}/libevent-release-2.1.12-stable.zip)
        endif ()

        include(ExternalProject)
        ExternalProject_Add(${EVENT_DirName}
                PREFIX ${EVENT_SOURCES_DIR}
                URL ${EVENT_URL} # file://${THIRD_PARTY_PATH}/libevent-release-2.1.12-stable.zip
                # -Dxxx 必须有CmakeLists.txt
                CMAKE_ARGS -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}
                CMAKE_ARGS -DBUILD_EXAMPLES=OFF
                CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EVENT_INSTALL_DIR}

                # 不是CmakeLists工程 需要使用configure编译
                #CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${EVENT_INSTALL_DIR}

                BUILD_COMMAND make -j
                # INSTALL_COMMAND make install
                INSTALL_DIR ${EVENT_INSTALL_DIR}
                ${EXTERNAL_PROJECT_LOG_ARGS}
                )

        ExternalProject_Get_Property(${EVENT_DirName} INSTALL_DIR)

        set(EVENT_INCLUDE_DIRS ${INSTALL_DIR}/include)

        set(EVENT_LIB_NAME "event")
        set(EVENT_LIBRARIES ${INSTALL_DIR}/lib/${LIBRARY_PREFIX}${EVENT_LIB_NAME}${LIBRARY_SUFFIX})

        list(APPEND PROJECT_EXTERNAL_DEPENDENCIES ${EVENT_DirName})
    endif ()

endif ()

