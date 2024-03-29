cmake_minimum_required(VERSION 3.10)
project(SWIGExample)

cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

if(NOT SWIG_EXECUTABLE)  
    message(FATAL_ERROR "******SWIG executable not found. Please make sure SWIG is installed and available in PATH.")  
endif()  

set_source_files_properties(example.i PROPERTIES CPLUSPLUS ON)
swig_add_library(example_swig_lib TYPE SHARED LANGUAGE cpp SOURCES example.i)
add_executable(example main.cpp)
target_link_libraries(example example_swig_lib)
