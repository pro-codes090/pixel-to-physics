cmake_minimum_required(VERSION 3.20)
project(Week.2 C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wshadow)

add_executable(Week.2 src/main.c)

target_include_directories(Week.2 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../sdl_lib/include")
target_link_libraries(Week.2 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../sdl_lib/lib/libSDL3.so")


target_link_libraries(Week.2 PUBLIC m)