cmake_minimum_required (VERSION 2.6)
project(muduo_test)
add_compile_options(-std=c++11)
include_directories(${PROJECT_SOURCE_DIR})
aux_source_directory("${PROJECT_SOURCE_DIR}/base" src)
aux_source_directory("${PROJECT_SOURCE_DIR}/net" src)
add_executable(muduo ${src})  
#add_subdirectory (test)
#echo ${PROJECT_BINARY_DIR}