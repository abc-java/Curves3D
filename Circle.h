#pragma once

#include <cmath>


#include "Curve.h"

class Circle : public Curve{
public:
    explicit Circle(double radius);
    Point3D GetPoint(double t) override;
    Vector3D GetDerivative(double t) override;
    std::string GetType() const override;
    double GetRadius() const;
private:
    double radius;
    std::string type;
};

