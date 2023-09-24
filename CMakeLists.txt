# CMakeList.txt : CMake project for terraria-clone, include source and define
cmake_minimum_required (VERSION 3.8)
project ("terraria-clone")


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(Stb REQUIRED)

include_directories(include/)

add_executable(${PROJECT_NAME} "src/main.cpp" "src/Game.cpp"   "src/Block.cpp")

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)
add_dependencies(${PROJECT_NAME} copy_assets)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)

