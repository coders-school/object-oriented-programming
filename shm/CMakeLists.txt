project(SHM)

add_executable(${PROJECT_NAME} main.cpp ship.cpp cargo.cpp island.cpp)

add_compile_options(${PROJECT_NAME} -Wall -Wextra -Wconversion -pedantic -Werror)
