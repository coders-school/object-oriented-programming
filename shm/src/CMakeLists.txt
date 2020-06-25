
set(SOURCES
    alcohol.cpp
    cargo.cpp
    coordinates.cpp
    dryfruit.cpp
    fruit.cpp
    island.cpp
    item.cpp
    map.cpp
    player.cpp
    ship.cpp
    store.cpp
    )

add_executable(${PROJECT_NAME} ../main.cpp ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wconversion)
target_include_directories(${PROJECT_NAME} PRIVATE inc)

add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})
