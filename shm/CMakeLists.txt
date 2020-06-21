cmake_minimum_required(VERSION 3.10)

project(SHM VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/alcohol.cpp
    src/cargo.cpp
    src/coordinates.cpp
    src/fruit.cpp
    src/item.cpp
    src/island.cpp
    src/map.cpp
    src/player.cpp
    src/ship.cpp)
    
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wconversion)
target_include_directories(${PROJECT_NAME} PRIVATE inc)
