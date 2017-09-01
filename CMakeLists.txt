cmake_minimum_required(VERSION 3.5)
project(safe_arithmetic)

set(CMAKE_C_STANDARD 99)

add_subdirectory(googletest)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(safe_arithmetic src/safe_arithmetic_int.c)
target_include_directories(safe_arithmetic PUBLIC include)

add_executable(safe_arithmetic_int_test test/safe_arithmetic_int_test.cpp)
target_link_libraries(safe_arithmetic_int_test safe_arithmetic gtest gtest_main)