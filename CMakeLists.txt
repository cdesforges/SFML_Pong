cmake_minimum_required(VERSION 3.27)
project(SFML_Pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(SFML_Pong main.cpp
        Player.cpp
        Player.h
        Ball.cpp
        Ball.h
        GameLogic.cpp
        GameLogic.h
        Menu.cpp
        Menu.h
)

target_link_libraries(SFML_Pong sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)