cmake_minimum_required(VERSION 3.10)
project(shm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})

set(SOURCES
    ${SOURCE_DIR}/Cargo.cpp
    ${SOURCE_DIR}/Island.cpp
    ${SOURCE_DIR}/Map.cpp
    ${SOURCE_DIR}/Ship.cpp
)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})
target_compile_options(${PROJECT_NAME}-lib PRIVATE -Wall -Wextra -Werror -pedantic -Wconversion -O3)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic -Wconversion -O3)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
