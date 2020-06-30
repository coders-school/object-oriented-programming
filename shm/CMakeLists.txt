cmake_minimum_required(VERSION 3.10)
project(SHM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
include_directories(src)

set(MAIN
    src/main.cpp)

set(SOURCES
    src/alcohol.cpp
    src/cargo.cpp
    src/fruit.cpp
    src/game.cpp
    src/island.cpp
    src/item.cpp
    src/map.cpp
    src/player.cpp
    src/ship.cpp
    src/time.cpp
)

set(HEADER_FILES
    include/alcohol.hpp
    include/cargo.hpp
    include/fruit.hpp
    include/game.hpp
    include/island.hpp
    include/item.hpp
    include/map.hpp
    include/player.hpp
    include/ship.hpp
    include/time.hpp
)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})

add_executable(${PROJECT_NAME} ${MAIN})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion)

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

