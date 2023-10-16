#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

static int COUNT_ELEM = 10;
static double PI = 3.14;

std::shared_ptr<Curve> GetRandomCurvePtr() {
    int num = rand() % 3;
    switch (num) {
        case 0:
            return std::make_shared<Circle>((rand() % 500) + 1);
        case 1:
            return std::make_shared<Ellipse>((rand() % 500) + 1, (rand() % 500) + 1);
        case 2:
            return std::make_shared<Helix>((rand() % 500) + 1, (rand() % 500) + 1);
        default:
            return nullptr;
    }

}

int main() {
    srand(time(nullptr));

    std::vector<std::shared_ptr<Curve>> curves(COUNT_ELEM);
    for (auto& curve : curves) {
        curve = GetRandomCurvePtr();
        std::cout << curve->GetPoint(PI/4) << " " << curve->GetDerivative(PI/4) << std::endl;
    }

    std::vector<std::shared_ptr<Circle>> circles;
    for (auto& curve : curves) {
        std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(curve);
        if (circle) {
            circles.push_back(circle);
        }
    }

    std::sort(circles.begin(),
              circles.end(),
              [](const std::shared_ptr<Circle>& lhs, const std::shared_ptr<Circle>& rhs) {
        return lhs->GetRadius() > rhs->GetRadius();
    });

    double sum_radius = 0;

    for (const auto& circle: circles) {
        sum_radius += circle->GetRadius();
    }


}
