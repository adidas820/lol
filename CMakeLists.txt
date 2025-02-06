cmake_minimum_required(VERSION 3.5.0)
project(rogue VERSION 0.1.0 LANGUAGES C CXX)

add_executable(rogue 
            src/main.cpp
            src/systems/MovementSystem.cpp
            src/core/Game.cpp)

