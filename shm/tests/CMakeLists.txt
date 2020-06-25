
enable_testing()

include_directories(mocks)

set(TEST_SOURCES
  coordinatesTest.cpp
)

add_executable(${PROJECT_NAME}_ut main.cpp ${TEST_SOURCES})

target_compile_options(${PROJECT_NAME}_ut PRIVATE -Wall -Wextra -Wpedantic -Wconversion)
target_link_libraries(${PROJECT_NAME}_ut PUBLIC ${PROJECT_NAME}_lib gtest_main gmock_main)
