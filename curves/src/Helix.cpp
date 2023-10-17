#include "Helix.h"


Helix::Helix(double radius, double step) : radius(radius), step(step), type("Helix"){
    if (radius <= 0) {
        throw std::invalid_argument("Helix: radius <= 0");
    }
    if (step <= 0) {
        throw std::invalid_argument("Helix: step <= 0");
    }
}

Vector3D Helix::GetDerivative(double t) {
    double dx = -radius * std::sin(t);
    double dy = radius * std::cos(t);
    double dz = step;
    return {dx, dy, dz};
}

Point3D Helix::GetPoint(double t) {
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
    double z = step * t;
    return {x, y, z};
}

double Helix::GetRadius() const {
    return radius;
}

double Helix::GetStep() const {
    return step;
}

std::string Helix::GetType() const {
    return type;
}
