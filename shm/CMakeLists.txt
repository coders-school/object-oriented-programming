cmake_minimum_required(VERSION 3.13)
project(SHM)

set(CPP_FILES cargo.cpp coordinates.cpp island.cpp player.cpp ship.hpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(FLAGS -Wall -Wextra -Wpedantic -Wconversion )

add_library(${PROJECT_NAME}-lib STATIC ${CPP_FILES})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})

add_executable(${PROJECT_NAME} main.cpp )
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})