cmake_minimum_required(VERSION 3.17)
project(CubeRotations)

set(CMAKE_CXX_STANDARD 14)

add_executable(CubeRotations CppApi/main.cpp CppApi/Cube.cpp CppApi/Cube.h CppApi/Rotations.cpp)