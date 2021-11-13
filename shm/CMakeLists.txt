cmake_minimum_required(VERSION 3.16)
project(shm)
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
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

add_executable(ShipTester gtest.cpp)
target_link_libraries(ShipTester gtest_main)
add_test(NAME ship_test COMMAND Ship)