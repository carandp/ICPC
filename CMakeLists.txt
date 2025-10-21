cmake_minimum_required(VERSION 3.29)
project(icpc)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/temp/*.cpp")

foreach(SRC_FILE ${SRC_FILES})
    file(RELATIVE_PATH REL_PATH ${CMAKE_SOURCE_DIR} ${SRC_FILE})
    string(REPLACE "/" "_" EXE_NAME ${REL_PATH})
    string(REPLACE " " "_" EXE_NAME ${EXE_NAME})
    string(REPLACE ".cpp" "" EXE_NAME ${EXE_NAME})
    add_executable(${EXE_NAME} ${SRC_FILE})
endforeach()