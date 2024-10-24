cmake_minimum_required(VERSION 3.29)
project(icpc)

set(CMAKE_CXX_STANDARD 20)

add_executable(icpc main.cpp
        Basics/DataTypes.cpp
        Basics/DataTypes.h)
