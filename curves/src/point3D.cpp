#include "point3D.h"

std::ostream& operator<<(std::ostream& out, const Point3D& point) {
    out << "Point3D(" << point.x << ", " << point.y << ", " << point.z << ")";
    return out;
}