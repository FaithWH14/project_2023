cmake_minimum_required(VERSION 3.0)

project("simple_math")

add_executable(${PROJECT_NAME} "source/main.cpp" "source/ssh_utils.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE "C:/Users/faithwh14/Desktop/screenshot/OCTOBER/30_learn/header")
