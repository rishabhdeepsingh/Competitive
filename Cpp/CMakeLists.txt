cmake_minimum_required(VERSION 3.14)
project(Cpp)
set(CMAKE_CXX_STANDARD 17)

add_executable(output output/main.cpp library/fast.hpp)
add_executable(testrunner testrunner/main.cpp library/fast.hpp)

file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp")
add_executable(test ${TASKS} ${HEADERS} library/fast.hpp)


