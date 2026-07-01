cmake_minimum_required(VERSION 3.10)
project(fenv)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(app ${SOURCES})

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)
target_link_libraries(app PRIVATE SFML::Graphics SFML::Window SFML::System)