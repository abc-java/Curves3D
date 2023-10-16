#pragma once

#include <iostream>

#include "Point3D.h"


class Vector3D {
public:
    Vector3D(double x, double y, double z);
    explicit Vector3D(Point3D point);
    Point3D GetPoint() const;
    double GetX() const;
    double GetY() const;
    double GetZ() const;
private:
    Point3D point;
};

std::ostream& operator<<(std::ostream& out, const Vector3D& vector);