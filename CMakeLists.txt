cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-g -O1 -Wall -Werror -fno-omit-frame-pointer `sdl2-config --libs --cflags` -lSDL2_ttf -lSDL2_image -lSDL2_audio")
set (CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(Capstone)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)
include_directories(${PROJECT_SOURCE_DIR}/games/Pong)
include_directories(${PROJECT_SOURCE_DIR}/games/ObstacleCourse)

file(GLOB SOURCES "src/*.cpp" "src/games/Pong/*.cpp" "src/games/ObstacleCourse/*.cpp")

add_executable(Capstone ${SOURCES})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(Capstone ${SDL2_LIBRARIES} SDL2_ttf SDL2_image SDL2_mixer)


