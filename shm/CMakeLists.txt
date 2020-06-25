cmake_minimum_required(VERSION 3.10)

project(shm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    alcohol.cpp
    cargo.cpp
    fruit.cpp
    island.cpp
    item.cpp
    map.cpp
    player.cpp
    ship.cpp)

set(FLAGS -Wall -Wextra -pedantic -Wconversion -Werror)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
