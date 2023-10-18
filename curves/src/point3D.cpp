#include "point3D.h"

std::ostream& operator<<(std::ostream& out, const Point3D& point) {
    out << "Point3D(" << point.x << ", " << point.y << ", " << point.z << ")";
    return out;
}
bool operator==(const Point3D& lhs, const Point3D& rhs) {
    double eps = 1e-7;
    return (std::abs(lhs.x - rhs.x) < eps) && (std::abs(lhs.y - rhs.y) < eps) && (std::abs(lhs.z - rhs.z) < eps);
}