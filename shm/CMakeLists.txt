cmake_minimum_required(VERSION 3.10.0)
project(SHM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/cargo.cpp
    src/island.cpp
    src/map.cpp
    src/player.cpp
    src/ship.cpp
)

set(HEADER_FILES
    include/cargo.hpp
    include/island.hpp
    include/map.hpp
    include/player.hpp
    include/ship.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADER_FILES})
add_compile_options(-Wall -Wextra -Wconversion -Wpedantic -Werror)
