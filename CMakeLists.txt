cmake_minimum_required(VERSION 3.27)
project(SFML_Pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(SFML_Pong main.cpp
        Components/Platform/PlatformModel.cpp
        Components/Platform/PlatformModel.h
        Components/Ball/BallModel.cpp
        Components/Ball/BallModel.h
        Components/Ball/BallView.cpp
        Components/Ball/BallView.h
        Collision/Collision.cpp
        Collision/Collision.h
        States/State.h
        States/StateManager.cpp
        States/StateManager.h
        States/MainGameState.cpp
        States/MainGameState.h
        Components/Component.h
        Components/Player/Player.cpp
        Components/Player/Player.h
        Components/Platform/Platform.cpp
        Components/Platform/Platform.h
        Components/Platform/PlatformView.cpp
        Components/Platform/PlatformView.h
        Components/Platform/PlatformController.cpp
        Components/Platform/PlatformController.h
        Components/Player/PlayerControls.h
        Components/Ball/BallController.cpp
        Components/Ball/BallController.h
        Components/Ball/Ball.cpp
        Components/Ball/Ball.h
        States/MenuState.cpp
        States/MenuState.h
        Pong.cpp
        Pong.h
        Collision/Collidable.h
        Components/Platform/Platform.cpp
        Components/Platform/Platform.h
        Components/Platform/PlatformModel.cpp
        Components/Platform/PlatformModel.h
        Components/Platform/PlatformView.cpp
        Components/Platform/PlatformView.h
        Components/Paddle/Paddle.cpp
        Components/Paddle/Paddle.h
        Components/Wall/Wall.cpp
        Components/Wall/Wall.h
)

target_link_libraries(SFML_Pong sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)