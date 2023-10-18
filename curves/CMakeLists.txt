cmake_minimum_required(VERSION 3.25)

project(CurvesLibrary)

set(SOURCE_LIB
        src/circle.cpp
        src/ellipse.cpp
        src/helix.cpp
        src/point3D.cpp
        src/vector3D.cpp)

add_library(CurvesLibrary SHARED ${SOURCE_LIB})