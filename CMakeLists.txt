cmake_minimum_required(VERSION 3.25)
project(Curves3D)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ${Curves3D_SOURCE_DIR}/curves/include
        ${Curves3D_SOURCE_DIR}/test
        ${Curves3D_SOURCE_DIR}/test_runner
)

add_executable(
        Curves3D
        main.cpp
        curves/include/curve.h
        curves/include/point3D.h
        curves/src/vector3D.cpp
        curves/include/vector3D.h
        curves/src/circle.cpp
        curves/include/circle.h
        curves/src/ellipse.cpp
        curves/include/ellipse.h
        curves/src/helix.cpp
        curves/include/helix.h
        curves/src/point3D.cpp
        test/test.cpp
        test/test.h
        test_runner/test_runner.h
        test_runner/test_runner.cpp
)




