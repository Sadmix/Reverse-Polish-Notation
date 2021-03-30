cmake_minimum_required(VERSION 3.10)

project(RPN)

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB SRC_DIR "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(RPN ${SRC_DIR})