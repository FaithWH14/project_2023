cmake_minimum_required(VERSION 3.5)

project(asio_learn)

add_executable(${PROJECT_NAME}  "main.cpp")

include_directories(${PROJECT_NAME} "C:/boost_1_83_0")

target_link_libraries(${PROJECT_NAME} PRIVATE "C:/boost_1_83_0/stage/lib/libboost_thread-vc143-mt-x64-1_83.lib"
                                              "C:/boost_1_83_0/stage/lib/libboost_chrono-vc143-mt-x64-1_83.lib")
