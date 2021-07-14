cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS -fno-rtti)

project(shmProject)

add_executable(${PROJECT_NAME} main.cpp Store.cpp Cargo.cpp DefaultCargo.cpp Item.cpp Fruit.cpp Alcohol.cpp Island.cpp Map.cpp Player.cpp Ship.cpp Time.cpp Timeable.cpp Warehouse.cpp DryFruit.cpp)
add_executable(${PROJECT_NAME}-ut Tests.cpp Store.cpp Cargo.cpp DefaultCargo.cpp Item.cpp Fruit.cpp Alcohol.cpp Player.cpp Ship.cpp Time.cpp Timeable.cpp Warehouse.cpp DryFruit.cpp)
