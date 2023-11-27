cmake_minimum_required(VERSION 3.5)

project(25_qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(25_qt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        login.h login.cpp
        styles.qss
        login_image.png
        page1.h page1.cpp
        test.jpg
        customtitlebar.h
    )
else()
    if(ANDROID)
        add_library(25_qt SHARED ${PROJECT_SOURCES})
    else()
        add_executable(25_qt ${PROJECT_SOURCES})
    endif()
endif()

# Set Boost include directory
include_directories("C:/boost_1_83_0")

# Link Boost libraries and ws2_32
target_link_libraries(25_qt PRIVATE
    "C:/boost_1_83_0/stage/lib/libboost_thread-vc143-mt-x64-1_83.lib"
    "C:/boost_1_83_0/stage/lib/libboost_chrono-vc143-mt-x64-1_83.lib"
    Qt${QT_VERSION_MAJOR}::Widgets
    ws2_32  # Link against the Winsock library
)

include(GNUInstallDirs)
install(TARGETS 25_qt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(25_qt)
endif()
