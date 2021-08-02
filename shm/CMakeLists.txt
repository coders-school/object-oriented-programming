cmake_minimum_required(VERSION 3.10)
 
project(SHM_2077)

set(FILES
    island.cpp
    map.cpp
    player.cpp
    ship.cpp
    coordinates.cpp
    cargo.cpp
    )

add_executable(${PROJECT_NAME} main.cpp ${FILES})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wconversion -O0)