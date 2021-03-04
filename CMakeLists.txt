cmake_minimum_required(VERSION 3.17)
project(CubeRotations)

find_package(Python COMPONENTS Interpreter Development)
find_package(PythonLibs 3.9 REQUIRED)
find_package(Boost COMPONENTS python39 REQUIRED)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_SHARED_MODULE_PREFIX "")

add_library(cube MODULE CppApi/main.cpp CppApi/Cube.cpp CppApi/Cube.h CppApi/Rotations.cpp CppApi/CubeConstants.h)

message(STATUS "${PYTHON_LIBRARIES}")
message(STATUS "${PYTHON_INCLUDE_DIRS}")

include_directories(${PYTHON_INCLUDE_DIRS})

target_link_libraries(cube ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
target_include_directories(cube PRIVATE ${PYTHON_INCLUDE_DIRS})

add_executable(CubeRotations CppApi/main.cpp CppApi/Cube.cpp CppApi/Cube.h CppApi/Rotations.cpp CppApi/CubeConstants.h)