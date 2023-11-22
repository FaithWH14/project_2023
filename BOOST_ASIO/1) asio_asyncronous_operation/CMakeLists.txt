cmake_minimum_required(VERSION 3.0)

SET(BOOST_ROOT C:/boost_1_83_0)
SET(BOOST_LIB ${BOOST_ROOT}/stage)

project(learn_asio)

add_executable(${PROJECT_NAME} "main.cpp")

include_directories(${PROJECT_NAME} "t3.h" "t4.h" ${BOOST_ROOT})
target_link_libraries(${PROJECT_NAME} PRIVATE ${BOOST_LIB})
