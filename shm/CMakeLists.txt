cmake_minimum_required(VERSION 2.8.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wconversion -Werror")

project(shm)

#TODO: Add your cpp file you implemented below, e.g. add_executable(${PROJECT_NAME} main.cpp ship.cpp)
add_executable(${PROJECT_NAME} main.cpp )
