cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(PointTest PointTest.cpp)

target_link_libraries(PointTest gtest gtest_main)

include_directories(../../library/*)