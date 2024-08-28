cmake_minimum_required(VERSION 3.30)
project(builder)

set(CMAKE_CXX_STANDARD 17)

add_executable(builder main.cpp
        Block.cpp
        Block.h
        BlockManager.cpp
        BlockManager.h
        Display.cpp
        Display.h
        Camera.cpp
        Camera.h
        glad.c
        mouse.h
        mouse.cpp
        init.h)
find_package(glfw3 REQUIRED)
target_link_libraries(builder glfw)