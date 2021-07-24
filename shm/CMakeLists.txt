cmake_minimum_required(VERSION 3.10)
project(shm)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
message("GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")
message("GTEST_LIBRARIES = ${GTEST_LIBRARIES}")

add_library(${PROJECT_NAME}-lib Cargo.cpp Fruit.cpp Alcohol.cpp Item.cpp Rarity.hpp Ship.cpp Player.cpp DryFruit.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

enable_testing()
add_executable(${PROJECT_NAME}-ut main-ut.cpp)
target_link_libraries(${PROJECT_NAME}-ut shm-lib ${GTEST_LIBRARIES} pthread)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)