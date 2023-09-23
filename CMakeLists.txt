# CMakeList.txt : CMake project for terraria-clone, include source and define
cmake_minimum_required (VERSION 3.8)
project ("terraria-clone")


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} "src/main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

