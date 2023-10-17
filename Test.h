#pragma once

#include <cmath>

#include "test_runner.h"
#include "Circle.h"
#include "Curve.h"
#include "Ellipse.h"
#include "Helix.h"

void Test();
void TestCircle();
void TestEllipse();
void TestHelix();

bool operator==(const Point3D& lhs, const Point3D& rhs);
bool operator==(const Vector3D& lhs, const Vector3D& rhs);