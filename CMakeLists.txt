cmake_minimum_required(VERSION 3.5)

project(CircularBuffer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
)

set(INCLUDE_DIRS
    inc
)

add_executable(CircularBuffer ${SOURCES})
target_include_directories(CircularBuffer PUBLIC ${INCLUDE_DIRS})

