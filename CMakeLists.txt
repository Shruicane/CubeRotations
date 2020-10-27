
cmake_minimum_required(VERSION 3.17)
project(CubeRotations)

set(CMAKE_CXX_STANDARD 14)

find_package(PythonLibs 3.8 REQUIRED)
#find_package(Boost COMPONENTS python38 REQUIRED)

set(CMAKE_SHARED_MODULE_PREFIX "")

add_library(cube MODULE CppApi/main.cpp CppApi/Cube.cpp CppApi/Cube.h CppApi/Rotations.cpp CppApi/CubeConstants.h)

target_link_libraries(cube ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
target_include_directories(cube PRIVATE ${PYTHON_INCLUDE_DIRS})



add_executable(CubeRotations CppApi/main.cpp CppApi/Cube.cpp CppApi/Cube.h CppApi/Rotations.cpp CppApi/CubeConstants.h)