cmake_minimum_required(VERSION 3.5)

set(TEST_NAME 006_api_copy_constructor)

project(${TEST_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    ${TEST_NAME}.cpp
)

set(INCLUDE_DIRS
    ../../inc
)

add_executable(${TEST_NAME} ${SOURCES})

target_include_directories(${TEST_NAME} PUBLIC ${INCLUDE_DIRS})

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})