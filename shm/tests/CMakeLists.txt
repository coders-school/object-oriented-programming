cmake_minimum_required(VERSION 3.10)

enable_testing()

include_directories(mocks)

set(TEST_SOURCES
  coordinatesTest.cpp
)

add_executable(${PROJECT_NAME}-ut main.cpp ${TEST_SOURCES})
target_compile_options(${PROJECT_NAME}-ut PRIVATE -Wall -Wextra -Wpedantic -Wconversion)
target_link_libraries(${PROJECT_NAME}-ut PUBLIC ${shm_lib} gtest gmock)

add_test(NAME Tests COMMAND ${PROJECT_NAME}-ut)
