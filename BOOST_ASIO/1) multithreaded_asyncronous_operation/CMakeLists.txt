cmake_minimum_required(VERSION 3.5)

set(BOOST_ROOT "C:/boost_1_83_0/")
set(BOOST_LIB "C:/boost_1_83_0/stage/lib/")

project(learn_asio)

add_executable(${PROJECT_NAME} "main.cpp" "t5.h")

include_directories(${PROJECT_NAME}
    "t3.h"
    "t4.h"
    "t5.h"
    ${BOOST_ROOT}
)

# Link against Boost libraries
target_link_libraries(${PROJECT_NAME} PRIVATE "C:/boost_1_83_0/stage/lib/libboost_thread-vc143-mt-x64-1_83.lib"
                                              "C:/boost_1_83_0/stage/lib/libboost_chrono-vc143-mt-x64-1_83.lib"
                                              ${BOOST_LIB})
