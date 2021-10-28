cmake_minimum_required(VERSION 3.10)
project(shm)

set(SRC 
    alcohol.cpp 
    cargo.cpp 
    coordinates.cpp 
    fruit.cpp
    Game.cpp 
    island.cpp 
    item.cpp 
    Map.cpp 
    Menu.cpp
    player.cpp 
    ship.cpp 
    Storable.cpp 
    Store.cpp 
    Time.cpp)
    
set(FLAGS -Wall -Wextra -Werror -Wconversion -O3)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})

add_executable(${PROJECT_NAME} main.cpp ${SRC})

#target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
