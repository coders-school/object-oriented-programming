cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(shmProject)

# # Download and unpack googletest at configure time
# configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
# execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#     RESULT_VARIABLE result
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
# if(result)
#     message(FATAL_ERROR "CMake step for googletest failed: ${result}")
# endif()
# execute_process(COMMAND ${CMAKE_COMMAND} --build .
#     RESULT_VARIABLE result
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
# if(result)
#     message(FATAL_ERROR "Build step for googletest failed: ${result}")
# endif()

# # Download and unpack googletest at configure time
# configure_file(CMakeLists2.txt.in catch2-download/CMakeLists.txt)
# execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#     RESULT_VARIABLE result
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/catch2-download )
# if(result)
#     message(FATAL_ERROR "CMake step for catch2 failed: ${result}")
# endif()
# execute_process(COMMAND ${CMAKE_COMMAND} --build .
#     RESULT_VARIABLE result
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/catch2-download )
# if(result)
#     message(FATAL_ERROR "Build step for catch2 failed: ${result}")
# endif()

# # Prevent overriding the parent project's compiler/linker
# # settings on Windows
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

find_package(Catch2 REQUIRED)

set(COMMAND_FILES
    Commands/ExitCommand.cpp
    Commands/MainMenuCommand.cpp
    Commands/NextDayCommand.cpp
    Commands/TradeBuyCommand.cpp
    Commands/TradeCommand.cpp
    Commands/TradeSellCommand.cpp
    Commands/TravelCommand.cpp)

set(CARGO_FILES
    Cargos/Cargo.cpp 
    Cargos/Item.cpp 
    Cargos/Fruit.cpp 
    Cargos/Alcohol.cpp 
    Cargos/DefaultCargo.cpp
    Cargos/DryFruit.cpp)

set(FILES 
    ${COMMAND_FILES}
    ${CARGO_FILES}
    Store.cpp 
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

set(FLAGS 
    -Wall -Wextra -Werror -pedantic -Wconversion
)
set(TEST_FLAGS -Wall -Wextra)

add_library(${PROJECT_NAME}-lib STATIC ${FILES})
add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-ut Tests/catch2/Tests.cpp
    build/Catch2-src/extras/catch_amalgamated.cpp)
add_executable(${PROJECT_NAME}-ut2 Tests/gtests/main.cpp)

set(DIRECTORIES 
    Cargos 
    Commands 
    .)

target_include_directories(${PROJECT_NAME} PRIVATE ${DIRECTORIES})
target_include_directories(${PROJECT_NAME}-lib PRIVATE ${DIRECTORIES})
target_include_directories(${PROJECT_NAME}-ut PRIVATE ${DIRECTORIES} 
    build/Catch2-src/extras)
target_include_directories(${PROJECT_NAME}-ut2 PRIVATE ${DIRECTORIES} 
    build/googletest-src/googletest/include)

target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${TEST_FLAGS})
target_compile_options(${PROJECT_NAME}-ut2 PRIVATE ${TEST_FLAGS})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut2 ${PROJECT_NAME}-lib -lgtest)

enable_testing()
add_test(NAME Tests-catch2 COMMAND ${PROJECT_NAME}-ut)
add_test(NAME Tests-gtest COMMAND ${PROJECT_NAME}-ut2)
