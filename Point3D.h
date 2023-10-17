#pragma once
#include <iostream>

struct Point3D {
    double x = 0;
    double y = 0;
    double z = 0;
};

std::ostream& operator<<(std::ostream& out, const Point3D& point);