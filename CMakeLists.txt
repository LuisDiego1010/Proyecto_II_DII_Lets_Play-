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

add_executable(client src/cpp/Client/main.cpp
        src/cpp/Client/Socket_Client.cpp
        src/cpp/Client/Socket_Client.h
        src/cpp/Client/Interface/mainWindow.cpp
        src/cpp/Client/Interface/mainWindow.h
        src/cpp/Client/Interface/BP/BpWindow.cpp
        src/cpp/Client/Interface/BP/BpWindow.h
        src/cpp/Client/Interface/PZ/PuzzleWindow.cpp
        src/cpp/Client/Interface/PZ/PuzzleWindow.h
        src/cpp/Client/Interface/BP/bpGameMode.cpp
        src/cpp/Client/Interface/BP/bpGameMode.h
        src/cpp/Client/Interface/PZ/puzzleGameMode.cpp
        src/cpp/Client/Interface/PZ/puzzleGameMode.h
        src/cpp/Client/Interface/InputBox.cpp
        src/cpp/Client/Interface/InputBox.h
        src/cpp/Client/Interface/BP/Line.cpp
        src/cpp/Client/Interface/BP/Line.h
        src/cpp/Client/Interface/BP/Collision.cpp
        src/cpp/Client/Interface/BP/Collision.h
        src/cpp/Client/Interface/Scroll.cpp
        src/cpp/Client/Interface/Scroll.h)
target_link_libraries(client
        sfml-graphics
        sfml-audio
        ${CONAN_LIBS})

add_executable(Server
        src/cpp/Server/main.cpp
        src/cpp/Server/Socket_Server.cpp
        src/cpp/Server/Socket_Server.h
        src/cpp/Server/PZ/PZ.cpp
        src/cpp/Server/PZ/PZ.h
        src/cpp/Server/PZ/Fila.cpp
        src/cpp/Server/BpServer/Backtracking.cpp
        src/cpp/Server/BpServer/Backtracking.h
        src/cpp/Server/BpServer/BpServer.cpp
        src/cpp/Server/BpServer/BpServer.h
        src/cpp/Server/PZ/Fila.h
        src/cpp/Server/PZ/Individuo.cpp
        src/cpp/Server/PZ/Individuo.h
        src/cpp/Server/PZ/Generation.cpp
        src/cpp/Server/PZ/Generation.h)
target_link_libraries(Server
        ${CONAN_LIBS})