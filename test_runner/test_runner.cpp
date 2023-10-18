#include "test_runner.h"

void AssertEqual(double x, double y, const std::string& hint = {}) {
    auto eps = 1e-7;
    if (std::abs(x-y) < eps) {
        std::ostringstream os;
        os << "Assertion failed: " << x << " != " << y;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw std::runtime_error(os.str());
    }
}

