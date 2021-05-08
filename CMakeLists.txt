cmake_minimum_required(VERSION 3.1)

project(Proyecto_II)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "/usr/include/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(client src/cpp/main.cpp)
target_link_libraries(client sfml-graphics sfml-audio)