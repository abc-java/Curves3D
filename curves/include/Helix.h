#pragma once

#include "Curve.h"
#include <cmath>

class Helix : public Curve {
public:
    Helix(double radius, double step);
    Vector3D GetDerivative(double t) override;
    Point3D GetPoint(double t) override;
    double GetRadius() const;
    double GetStep() const;
    std::string GetType() const override;
private:
    double radius;
    double step;
    std::string type;
};
