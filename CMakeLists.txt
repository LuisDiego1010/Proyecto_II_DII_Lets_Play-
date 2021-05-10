cmake_minimum_required(VERSION 3.1)

project(Proyecto_II)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
set(CMAKE_PREFIX_PATH ${CONAN_LIBS})

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "/usr/include/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(client src/cpp/main.cpp
        src/cpp/Socket.cpp
        src/cpp/Socket.h)
target_link_libraries(client
        sfml-graphics
        sfml-audio
        ${CONAN_LIBS})

add_executable(Server
        src/cpp/Server/main.cpp src/cpp/Server/Socket.cpp src/cpp/Server/Socket.h)
target_link_libraries(client
        ${CONAN_LIBS})