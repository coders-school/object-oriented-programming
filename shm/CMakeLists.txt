cmake_minimum_required(VERSION 3.10)
project(shm)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")

add_library(shm-lib Cargo.cpp Fruit.cpp Alcohol.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

add_executable(${PROJECT_NAME}-ut main-ut.cpp)
target_link_libraries(${PROJECT_NAME}-ut shm-lib pthread ${GTEST_LIBRARIES})