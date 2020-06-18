cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SHM)
file(GLOB SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
add_compile_options(-Wall -Wextra -Wconversion -pedantic -Werror)
