cmake_minimum_required( VERSION 3.21 )

# 设置输出目录为 build 目录  
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)  
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)  
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

set( KICAD_CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" )

message(STATUS "Hello World!")

project( test1 )

message(STATUS "Hello World!")

add_executable(TEST main.cc)