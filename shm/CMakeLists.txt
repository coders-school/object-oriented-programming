cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(shmProject)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        master
)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        devel
)

# After the following call, the CMake targets defined by googletest and
# Catch2 will be defined and available to the rest of the build

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest Catch2)

# include(GoogleTest)
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
add_executable(${PROJECT_NAME}-ut Tests/catch2/Tests.cpp)
add_executable(${PROJECT_NAME}-ut2 Tests/gtests/main.cpp)

set(DIRECTORIES 
    Cargos 
    Commands 
    .)

target_include_directories(${PROJECT_NAME} PRIVATE ${DIRECTORIES})
target_include_directories(${PROJECT_NAME}-lib PRIVATE ${DIRECTORIES})
target_include_directories(${PROJECT_NAME}-ut PRIVATE ${DIRECTORIES})
target_include_directories(${PROJECT_NAME}-ut2 PRIVATE ${DIRECTORIES})

target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${TEST_FLAGS})
target_compile_options(${PROJECT_NAME}-ut2 PRIVATE ${TEST_FLAGS})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib Catch2::Catch2WithMain)
target_link_libraries(${PROJECT_NAME}-ut2 ${PROJECT_NAME}-lib gtest_main)

enable_testing()
add_test(NAME Tests-catch2 COMMAND ${PROJECT_NAME}-ut)
add_test(NAME Tests-gtest COMMAND ${PROJECT_NAME}-ut2)
