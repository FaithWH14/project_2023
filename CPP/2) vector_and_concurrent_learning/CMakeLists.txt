cmake_minimum_required(VERSION 3.0)

project("vector_learn")

add_executable(${PROJECT_NAME} "./source/main.cpp" "./source/utils.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE "./header")
