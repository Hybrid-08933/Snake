cmake_minimum_required(VERSION 3.15)
project(snake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -O3 --std=c99)
