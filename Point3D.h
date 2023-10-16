#pragma once
#include <iostream>

struct Point3D {
    double x;
    double y;
    double z;
};

std::ostream& operator<<(std::ostream& out, const Point3D& point);