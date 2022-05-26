cmake_minimum_required(VERSION 3.14)

project(govnocode LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES *.cpp)
file(GLOB_RECURSE HEADERS *.h)

add_executable(govnocode ${HEADERS} ${SOURCES} main.cpp)
