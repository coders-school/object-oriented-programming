cmake_minimum_required(VERSION 3.10)
project(SHM)
FILE(GLOB SRC_FILES "*.cpp")
list(REMOVE_ITEM SRC_FILES main.cpp test.cpp)

set(FLAGS
        -Wall
        -Wextra
        -Werror
        -pedantic
        -Wconversion
        )

add_library(${PROJECT_NAME}-lib STATIC ${SRC_FILES})

#This will be used when proper main or test file will be created
#[[
add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})

enable_testing()

add_test(Name shmTest COMMAND ${PROJECT_NAME}-ut)
]]