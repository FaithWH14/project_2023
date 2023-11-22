cmake_minimum_required(VERSION 3.0)

project(run_math123)

add_executable(run_math main.cpp)

target_include_directories(run_math PRIVATE "${CMAKE_SOURCE_DIR}/../math123")

target_link_directories(run_math PRIVATE "${CMAKE_SOURCE_DIR}/../math123/build/Release")

target_link_libraries(run_math learn)
