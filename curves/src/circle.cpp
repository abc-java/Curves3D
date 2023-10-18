#include "circle.h"

Circle::Circle(double radius) : radius(radius) {
    if (radius <= 0) {
        throw std::invalid_argument("Circle: radius <= 0");
    }
}

Point3D Circle::GetPoint(double t) {
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
    return {x, y, 0};
}

Vector3D Circle::GetDerivative(double t) {
    double dx = -radius * std::sin(t);
    double dy = radius * std::cos(t);
    return Vector3D{dx, dy, 0};
}

double Circle::GetRadius() const {
    return radius;
}

std::string Circle::GetType() const {
    return type;
}
