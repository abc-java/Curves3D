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
        curves/include/Curve.h
        curves/include/Point3D.h
        curves/src/Vector3D.cpp
        curves/include/Vector3D.h
        curves/src/Circle.cpp
        curves/include/Circle.h
        curves/src/Ellipse.cpp
        curves/include/Ellipse.h
        curves/src/Helix.cpp
        curves/include/Helix.h
        curves/src/Point3D.cpp
        test/Test.cpp
        test/Test.h
        test_runner/test_runner.h
        test_runner/test_runner.cpp
)
