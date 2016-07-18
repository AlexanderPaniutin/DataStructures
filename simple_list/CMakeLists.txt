cmake_minimum_required (VERSION 2.6)
project (simple_list)

set (LIST_DIR ${CMAKE_SOURCE_DIR})
set (EXECUTABLE_OUTPUT_PATH ${LIST_DIR}/bin)
#set (OUTPUT_NAME simple_list)

include_directories ("$ENV{GTEST_ROOT}/include")
link_directories ("$ENV{GTEST_ROOT}/make")
link_libraries ("libgtest_main.a")

add_executable(test_simple_list src/simple_list.h
                    src/test_simple_list.cpp)
