cmake_minimum_required (VERSION 2.6)
project (heap)

set (LIST_DIR ${CMAKE_SOURCE_DIR})
set (EXECUTABLE_OUTPUT_PATH ${LIST_DIR}/bin)

include_directories ("$ENV{GTEST_ROOT}/include")
link_directories ("$ENV{GTEST_ROOT}/make")
link_libraries ("libgtest_main.a")

add_executable(test_max_heap src/max_heap.h
        src/test_max_heap.cpp)
add_executable(test_min_heap src/min_heap.h
        src/test_min_heap.cpp)
