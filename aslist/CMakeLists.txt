cmake_minimum_required (VERSION 2.6)
project (aslist)

set (LIST_DIR ${CMAKE_SOURCE_DIR})
set (EXECUTABLE_OUTPUT_PATH ${LIST_DIR}/bin)
#set (OUTPUT_NAME test_aslist)

include_directories ("$ENV{GTEST_ROOT}/include")
link_directories ("$ENV{GTEST_ROOT}/make")
link_libraries ("libgtest_main.a")

add_executable(test_aslist src/aslist.cpp
                    src/test_aslist.cpp)
