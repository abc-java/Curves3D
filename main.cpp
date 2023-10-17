#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include "Test.h"
#include "test_runner.h"



std::shared_ptr<Curve> GetRandomCurvePtr() {
    const int COUNT_TYPE_CURVE = 3;
    const int CIRCLE = 0;
    const int ELLIPSE = 1;
    const int HELIX = 2;

    const int left = 1;
    const int right = 500;


    int type = rand() % COUNT_TYPE_CURVE;
    switch (type) {
        case CIRCLE:
            return std::make_shared<Circle>((rand() % right) + left);
        case ELLIPSE:
            return std::make_shared<Ellipse>((rand() % right) + left, (rand() % right) + left);
        case HELIX:
            return std::make_shared<Helix>((rand() % right) + left, (rand() % right) + left);
        default:
            return nullptr;
    }

}

int main() {
    static int COUNT_ELEM = 10;
    static double PI = 3.1415926535;

    TestRunner tr;
    RUN_TEST(tr, Test);

    srand(time(nullptr));

    std::vector<std::shared_ptr<Curve>> curves(COUNT_ELEM); // 2,3
    for (auto& curve : curves) {
        curve = GetRandomCurvePtr();
        std::cout << curve->GetType() << " " <<curve->GetPoint(PI/4) << " " << curve->GetDerivative(PI/4) << std::endl;
    }

    std::vector<std::shared_ptr<Circle>> circles; // 4
    for (auto& curve     : curves) {
        std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(curve);
        if (circle) {
            circles.push_back(circle);
        }
    }

    for (const auto& circle : circles) {
        std::cout << circle->GetType() << " " << circle->GetRadius() << std::endl;
    }

    std::sort(circles.begin(), // 5
              circles.end(),
              [](const std::shared_ptr<Circle>& lhs, const std::shared_ptr<Circle>& rhs) {
        return lhs->GetRadius() < rhs->GetRadius();
    });

    std::cout << '\n';

    for (const auto& circle : circles) {
        std::cout << circle->GetType() << " " << circle->GetRadius() << std::endl;
    }

    double sum_radius = 0; // 6

    for (const auto& circle: circles) {
        sum_radius += circle->GetRadius();
    }

    std::cout << "Sum radius: " << sum_radius << std::endl;


}
