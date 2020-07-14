cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-g -Wall -Werror `sdl2-config --libs --cflags` -lSDL2_ttf -lSDL2_image")
set (CMAKE_CXX_FLAGS, "${CXX_FLAGS} -pthread")

project(Capstone)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(Threads REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)
include_directories(${PROJECT_SOURCE_DIR}/animation)

file(GLOB SOURCES "src/*.cpp" "src/animation/*.cpp")

add_executable(Capstone ${SOURCES})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(Capstone ${SDL2_LIBRARIES} SDL2_ttf SDL2_image Threads::Threads)
