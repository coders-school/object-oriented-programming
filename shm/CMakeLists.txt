cmake_minimum_required(VERSION 3.10)
project(shm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/..)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

set(SOURCES
<<<<<<< HEAD
=======
    ${SOURCE_DIR}/Alcohol.cpp
    ${SOURCE_DIR}/Cargo.cpp
>>>>>>> ffa2f7ce138d013a60804c93b40d385aebed9463
    ${SOURCE_DIR}/Island.cpp
    ${SOURCE_DIR}/Cargo.cpp
    ${SOURCE_DIR}/Map.cpp
    ${SOURCE_DIR}/Ship.cpp
    ${SOURCE_DIR}/Fruit.cpp
)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME}-lib PUBLIC ${INCLUDE_DIR})
target_compile_options(${PROJECT_NAME}-lib PRIVATE -Wall -Wextra -Werror -pedantic -Wconversion)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic -Wconversion)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
