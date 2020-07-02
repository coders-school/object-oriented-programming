cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME SHM)
project(${PROJECT_NAME})
FILE(GLOB SRC_FILES "*.cpp")

add_library(${PROJECT_NAME}-lib STATIC ${SRC_FILES})

#This will be used when proper main or test file will be created
#add_executable(${PROJECT_NAME} main.cpp)
#add_executable(${PROJECT_NAME}-ut test.cpp)