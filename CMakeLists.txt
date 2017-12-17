cmake_minimum_required (VERSION 2.6)
project(muduo_test)
add_compile_options(-std=c++11)
ADD_SUBDIRECTORY(muduo)#编译muduo为lib
ADD_SUBDIRECTORY(test)#编译test目录
#add_executable(muduo ${src})  
#add_subdirectory (test)
#echo ${PROJECT_BINARY_DIR}