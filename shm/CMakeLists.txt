cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project(shm 
    HOMEPAGE_URL https://github.com/Marcinati/object-oriented-programming.git)

set(SRC
    alcohol.cpp
    cargo.cpp
    coordinates.cpp
    fruit.cpp
    game.cpp
    island.cpp
    item.cpp
    map.cpp
    player.cpp
    ship.cpp
    timeSHM.cpp)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

set(FLAGS
#    -Wall //some errors to resolve
    -Wextra
    -Werror
    -pedantic
    -Wconversion
    -O3)

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
