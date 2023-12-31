//
// Created by maksim on 16.10.23.
//

#include "vector3D.h"

Vector3D::Vector3D(double x, double y, double z = 0) : point({x, y, z}) {

}

Vector3D::Vector3D(Point3D point) : point(point){

}

Point3D Vector3D::GetPoint() const {
    return point;
}

double Vector3D::GetX() const {
    return point.x;
}

double Vector3D::GetY() const {
    return point.y;
}

double Vector3D::GetZ() const {
    return point.z;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& vector) {
    auto point = vector.GetPoint();
    out << "Vector3D(" << point.x << ", " << point.y << ", " << point.z << ")";
    return out;
}

bool operator==(const Vector3D& lhs, const Vector3D& rhs) {
    return lhs.GetPoint() == rhs.GetPoint();
}
