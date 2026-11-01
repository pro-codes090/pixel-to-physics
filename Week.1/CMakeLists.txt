cmake_minimum_required(VERSION 3.20)
project(week01_ppm C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wshadow)

add_executable(Week.1 src/main.c)
target_link_libraries(Week.1 PUBLIC m)