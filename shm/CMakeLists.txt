cmake_minimum_required(VERSION 3.14)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
project(SHM_2077)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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

add_executable(ShipTest_gt test/ship_gt.cpp ${FILES})
target_link_libraries(ShipTest_gt gtest_main)
target_link_directories(ShipTest_gt PUBLIC ${CMAKE_SOURCE_DIR})
add_test(NAME ShipTest COMMAND Ship)


target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})