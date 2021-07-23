cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
project(shmProject)

set(FILES 
    Store.cpp 
    Cargos/Cargo.cpp 
    Cargos/Item.cpp 
    Cargos/Fruit.cpp 
    Cargos/Alcohol.cpp 
    Cargos/DefaultCargo.cpp
    Cargos/DryFruit.cpp 
    Island.cpp 
    Map.cpp 
    Player.cpp 
    Ship.cpp 
    Time.cpp 
    Timeable.cpp 
    Warehouse.cpp
    Game.cpp
    Perishable.cpp
    GeneralPrint.cpp)

set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion)

add_library(${PROJECT_NAME}-lib STATIC ${FILES})
add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-ut Tests/Tests.cpp)

target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)

enable_testing()
add_test(NAME Tests COMMAND ${PROJECT_NAME}-ut)
