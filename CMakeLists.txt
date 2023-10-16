cmake_minimum_required(VERSION 3.25)
project(Curves3D)

set(CMAKE_CXX_STANDARD 17)

add_executable(Curves3D main.cpp Curve.h Point3D.h Vector3D.cpp Vector3D.h Circle.cpp Circle.h Ellipse.cpp Ellipse.h Helix.cpp Helix.h Point3D.cpp)
