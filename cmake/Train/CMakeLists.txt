cmake_minimum_required(VERSION 3.1)

project(Train)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./pcbcommon)
add_subdirectory(pcbcommon)

add_compile_definitions(MARS_USE_OPENGL)
#add_compile_options(MARS_OPENGL)

set(MARS_MAIN
  main.cc
)

add_executable(train ${MARS_MAIN})
target_link_libraries(train pcbcommon)