cmake_minimum_required(VERSION 3.0)

project(PixelQt VERSION 1.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES_LIB
    qtcolorpicker.cpp
    qtcolortriangle.cpp
    qtwindowlistmenu.cpp
)
set(HEADERS_LIB
    global.h
    qtcolorpicker.h
    qtcolortriangle.h
    qtwindowlistmenu.h
)

add_definitions(-DAPP_LIBRARY)

find_package(Qt5 5.12 REQUIRED Core Gui Widgets)

if(NOT WIN32)
    add_compile_options(-Wall -Wextra)
endif()

if(CMAKE_BUILD_TYPE MATCHES "^(release|Release|RELEASE)$")
    add_definitions(-DQT_NO_DEBUG_OUTPUT)
else()
    add_definitions(-DQT_MESSAGELOGCONTEXT)
endif()

if(APPLE)
    set(CMAKE_INSTALL_RPATH "@executable_path/../Frameworks")
endif()

add_library(
    ${PROJECT_NAME}
    SHARED
    ${SOURCES_LIB}
    ${HEADERS_LIB}
)
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    VERSION
    ${PROJECT_VERSION}
)
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    SOVERSION
    ${PROJECT_VERSION_MAJOR}
)
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    SOVERSION
    ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

target_link_libraries(
    ${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

if(UNIX AND NOT APPLE)
    include(GNUInstallDirs)
    if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
        set(LIB_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR})
    else()
        set(LIB_INSTALL_DIR ${CMAKE_INSTALL_FULL_LIBDIR})
    endif()
    install(TARGETS ${PROJECT_NAME} DESTINATION ${LIB_INSTALL_DIR})
endif()
