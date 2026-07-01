cmake_minimum_required(VERSION 3.10)
project(fenv)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(app
    src/main.cpp
    src/TileMap.cpp
    src/Organism.cpp
    src/Animal.cpp
    src/WorldMap.cpp
)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)
target_link_libraries(app PRIVATE SFML::Graphics SFML::Window SFML::System)