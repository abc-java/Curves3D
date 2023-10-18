#pragma once

#include <cmath>

#include "curve.h"
#include <stdexcept>

class Ellipse : public Curve {
public:
    Ellipse(double rx, double ry);
    Point3D GetPoint(double t) override;
    Vector3D GetDerivative(double t) override;
    std::string GetType() const override;
    double GetRX() const;
    double GetRY() const;

private:
    double rx;
    double ry;
    constexpr static auto type = "Ellipse";
};
