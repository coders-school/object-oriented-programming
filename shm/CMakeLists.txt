cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(shm 
    HOMEPAGE_URL https://github.com/Marcinati/object-oriented-programming.git)

set(SRC
    cargo.cpp
    coordinates.cpp
    island.cpp
    map.cpp
    player.cpp
    ship.cpp
    time.cpp)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})
add_executable(${PROJECT_NAME} main.cpp)

set(FLAGS
#    -Wall //add when item will have a constructor
#    -Wextra
    -Werror
    -pedantic
    -Wconversion
    -O3)

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
