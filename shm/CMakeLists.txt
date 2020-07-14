cmake_minimum_required(VERSION 3.10)

project(shm VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(shm_lib ${PROJECT_NAME}_lib)

include_directories(inc)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)
