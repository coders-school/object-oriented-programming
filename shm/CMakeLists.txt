cmake_minimum_required(VERSION 3.10)
 
project(SHM_2077)

set(FILES
    island.cpp
    map.cpp
    player.cpp
    ship.cpp
    coordinates.cpp
    cargo.cpp
    store.cpp
    alcohol.cpp
    item.cpp 
    fruit.cpp
    time.cpp
    game.cpp
    )

set(FLAGS 
    -Wall 
    #-Wextra 
    -Wpedantic 
    -Wconversion 
    -O0)

add_executable(${PROJECT_NAME} main.cpp ${FILES})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})