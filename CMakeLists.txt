cmake_minimum_required(VERSION 3.5)
project(Student-personal-financial-management)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/Localtime.cpp src/main_test.cpp src/User.cpp src/uinput.cpp src/User.h src/File.cpp )
add_executable(Student-personal-financial-management ${SOURCE_FILES})