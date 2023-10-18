cmake_minimum_required(VERSION 3.25)

project(Curves3D)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")

include_directories(curves/include)

add_executable(Curves3D main.cpp)

add_subdirectory(curves)

target_link_libraries(Curves3D CurvesLibrary)








