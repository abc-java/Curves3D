#include "Ellipse.h"

Ellipse::Ellipse(double rx, double ry) : rx(rx), ry(ry){
    if (rx <= 0) {
        throw std::invalid_argument("Ellipse: RX <= 0");
    }
    if (ry <= 0) {
        throw std::invalid_argument("Ellipse: RY <= 0");
    }
}

Vector3D Ellipse::GetDerivative(double t) {
    double dx = -rx * std::sin(t);
    double dy = ry * std::cos(t);
    return {dx, dy, 0};
}

Point3D Ellipse::GetPoint(double t) {
    double x = rx * std::cos(t);
    double y = ry * std::sin(t);
    return Point3D{x, y, 0};
}

double Ellipse::GetRX() const {
    return rx;
}

double Ellipse::GetRY() const {
    return ry;
}
