cmake_minimum_required(VERSION 3.0)
# cmake的官方文档：https://cmake.org/cmake/help/v3.20/guide/tutorial/index.html

# 设定工程名和版本号
project (cprojs VERSION 1.0)

#设置C编译器
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_FLAGS "-g -Wall -I D:\\Programs\\mingw64\\include -L D:\\Programs\\mingw64\\lib")

#设置Cpp编译器
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-g -Wall -I D:\\Programs\\mingw64\\include -L D:\\Programs\\mingw64\\lib")

set(PATH_LOGGER ${CMAKE_CURRENT_SOURCE_DIR}/easylogger)
message(STATUS "PATH_LOGGER is: " ${PATH_LOGGER})

set(SRC_LIST main.c leecode.c demo.c)
add_executable(main ${SRC_LIST})
message(STATUS "SRC_LIST: " ${SRC_LIST})