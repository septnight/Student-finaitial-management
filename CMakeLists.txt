cmake_minimum_required(VERSION 3.5)
project(Student-personal-financial-management)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/File.cpp src/Localtime.cpp src/uinput.cpp src/main_test.cpp src/Analysis/DataAnalysis.h)
add_executable(Student-personal-financial-management ${SOURCE_FILES})