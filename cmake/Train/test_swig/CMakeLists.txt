cmake_minimum_required(VERSION 3.10)  
project(MyProject)  
  
# 查找SWIG  
find_package(SWIG REQUIRED)  
include(${SWIG_USE_FILE})  
  
# 查找你的C++编译器  
find_package(CXX REQUIRED)  
  
# 设置你的源文件和接口文件  
set(MY_INTERFACE_FILE "my_interface.i")  
set(MY_SOURCE_FILES "my_source.c")  
  
# 配置SWIG以生成CXX代码  
set(CMAKE_SWIG_FLAGS "-c++")  
set_source_files_properties(${MY_INTERFACE_FILE} PROPERTIES CPLUSPLUS ON)  
swig_add_module(MyModule ${MY_INTERFACE_FILE} ${MY_SOURCE_FILES})  
swig_link_libraries(MyModule)  
  
# 添加你的CXX源文件  
add_library(MyLibrary SHARED ${MyModule_WRAPPED_SOURCE})  
target_link_libraries(MyLibrary PRIVATE ${MY_SOURCE_FILES})  
  
# 添加你的安装规则（如果需要）  
#install(TARGETS MyLibrary DESTINATION lib)