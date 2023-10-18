#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <omp.h>

#include "curve.h"
#include "circle.h"
#include "ellipse.h"
#include "helix.h"

std::shared_ptr<Curve> GetRandomCurvePtr() {

    constexpr int COUNT_TYPE_CURVE = 3;
    constexpr int CIRCLE = 0;
    constexpr int ELLIPSE = 1;
    constexpr int HELIX = 2;

    constexpr int left = 1;
    constexpr int right = 500;


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

    constexpr int COUNT_ELEM = 10;
    constexpr double PI = 3.1415926535;


    srand(time(nullptr));

    std::vector<std::shared_ptr<Curve>> curves(COUNT_ELEM); // 2,3
    for (auto& curve : curves) {
        curve = GetRandomCurvePtr();
        std::cout << curve->GetType() << " " << curve->GetPoint(PI/4) << " " << curve->GetDerivative(PI/4) << std::endl;
    }

    std::vector<std::shared_ptr<Circle>> circles; // 4
    for (auto& curve     : curves) {
        if (std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circle);
            std::cout << circle->GetType() << " " << circle->GetRadius() << std::endl;
        }

    }

    std::sort(circles.begin(), // 5
              circles.end(),
              [](const std::shared_ptr<Circle>& lhs, const std::shared_ptr<Circle>& rhs) {
        return lhs->GetRadius() < rhs->GetRadius();
    });

    std::cout << "\nsorted:\n";

    for (const auto& circle : circles) {
        std::cout << circle->GetType() << " " << circle->GetRadius() << std::endl;
    }


    double sum_radius = 0; // 6
#pragma omp parallel shared(circles) reduction (+: sum_radius) num_threads(2) default(none)
    {
#pragma omp for
        for (const auto &circle: circles) {
            sum_radius += circle->GetRadius();
        }
    }

    std::cout << "Sum radius: " << sum_radius << std::endl;


}
