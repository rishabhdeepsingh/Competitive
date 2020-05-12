cmake_minimum_required(VERSION 3.14)
project(Cpp)
set(CMAKE_CXX_STANDARD 17)

file(GLOB HEADERS "library/*")
add_executable(output output/main.cpp ${GLOB})
add_executable(testrunner testrunner/main.cpp)

# Dont change it
file(GLOB TASKS "tasks/*.cpp")
file(GLOB CONTESTS "contests/*.cpp")

file(GLOB HEADERS "library/*.hpp")

add_executable(test ${TASKS} ${HEADERS})

add_definitions(-DLOCAL)
add_definitions(-Wno-unused-result)
add_definitions(-Wshadow)
add_definitions(-Wall)
add_definitions(-fbounds-check)

add_executable(gen output/gen.cpp)
