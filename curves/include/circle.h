#pragma once

#include <cmath>


#include "curve.h"

class Circle : public Curve{
public:
    explicit Circle(double radius);
    Point3D GetPoint(double t) override;
    Vector3D GetDerivative(double t) override;
    std::string GetType() const override;
    double GetRadius() const;
private:
    double radius;
    constexpr static auto type = "Circle";
};

