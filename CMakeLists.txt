cmake_minimum_required(VERSION 3.5)

if(GENERATE_COVERAGE_REPORT)
    add_compile_options(-fprofile-arcs -ftest-coverage)
    set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
    set(BUILD_TESTING ON)
    link_libraries(gcov)
endif()

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

enable_testing()
add_subdirectory(test)