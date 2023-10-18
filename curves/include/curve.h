#pragma once

#include <string>

#include "point3D.h"
#include "vector3D.h"


class Curve {
public:
    virtual Point3D GetPoint(double t) = 0;
    virtual Vector3D GetDerivative(double t) = 0;
    virtual std::string GetType() const = 0;
private:

};