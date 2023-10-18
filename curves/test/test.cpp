#include "test.h"

void Test() {
    TestRunner tr;
    RUN_TEST(tr, TestHelix);
    RUN_TEST(tr, TestEllipse);
    RUN_TEST(tr, TestCircle);
}



void TestCircle() {
    double PI = 3.1415926535;

    {
        bool flag = false;
        try {
            Circle c(-1);
        } catch (std::exception& ex) {
            flag = true;
        }
        ASSERT(flag);
    }
    {
        Circle c(1);
        ASSERT_EQUAL(1, c.GetRadius())
    }
    {
        Circle c(10);
        ASSERT_EQUAL("Circle", c.GetType());
    }
    {
        Circle c(1);

        Point3D expected{1, 0};
        ASSERT_EQUAL(expected, c.GetPoint(0));

        expected = Point3D{-1, 0};
        ASSERT_EQUAL(expected, c.GetPoint(PI))

        expected = Point3D{0, 1};
        ASSERT_EQUAL(expected, c.GetPoint(PI/2));

        expected = Point3D{0, -1};
        ASSERT_EQUAL(expected, c.GetPoint((3*PI)/2));
    }
    {
        Circle c(1);

        Vector3D expected{0, 1, 0};
        ASSERT_EQUAL(expected, c.GetDerivative(0));

        expected = Vector3D{0, -1, 0};
        ASSERT_EQUAL(expected, c.GetDerivative(PI))

        expected = Vector3D{-1, 0, 0};
        ASSERT_EQUAL(expected, c.GetDerivative((PI)/2));

        expected = Vector3D{1, 0, 0};
        ASSERT_EQUAL(expected, c.GetDerivative((3*PI)/2));
    }
}

void TestEllipse() {
    long double PI = 3.1415926535;
    {
        bool flag = false;
        try {
            Ellipse e(-1, 1);
        } catch (std::exception& ex) {
            flag = true;
        }
        ASSERT(flag);

        flag = false;
        try {
            Ellipse e(1, -1);
        } catch (std::exception& ex) {
            flag = true;
        }
        ASSERT(flag);

        flag = false;
        try {
            Ellipse e(-1, -1);
        } catch (std::exception& ex) {
            flag = true;
        }
        ASSERT(flag);
    }
    {
        Ellipse e(1, 5);
        ASSERT_EQUAL(1, e.GetRX());
        ASSERT_EQUAL(5, e.GetRY());
    }
    {
        Ellipse e(10, 1);
        ASSERT_EQUAL("Ellipse", e.GetType());
    }
    {
        Ellipse e(0.5, 1);

        Point3D expected{0.5, 0};
        ASSERT_EQUAL(expected, e.GetPoint(0));

        expected = Point3D{-0.5, 0};
        ASSERT_EQUAL(expected, e.GetPoint(PI))

        expected = Point3D{0, 1};
        ASSERT_EQUAL(expected, e.GetPoint(PI/2));

        expected = Point3D{0, -1};
        ASSERT_EQUAL(expected, e.GetPoint((3*PI)/2));
    }
    {
        Ellipse e(0.5, 1);

        Vector3D expected{0, 1, 0};
        ASSERT_EQUAL(expected, e.GetDerivative(0));

        expected = Vector3D{0, -1, 0};
        ASSERT_EQUAL(expected, e.GetDerivative(PI))

        expected = Vector3D{-0.5, 0, 0};
        ASSERT_EQUAL(expected, e.GetDerivative(PI/2));

        expected = Vector3D{0.5, 0, 0};
        ASSERT_EQUAL(expected, e.GetDerivative((3*PI)/2));
    }
}

void TestHelix() {
    double PI = 3.1415926535;
    {
        bool flag = false;
        try {
            Helix h(-1, 1);
        } catch (std::exception& ex) {
            flag = true;
        }
        ASSERT(flag);

        flag = false;
        try {
            Helix h(1, -1);
        } catch (std::exception& ex) {
            flag = true;
        }
        ASSERT(flag);

        flag = false;
        try {
            Helix h(-1, -1);
        } catch (std::exception& ex) {
            flag = true;
        }
        ASSERT(flag);
    }
    {
        Helix h(1, 5);
        ASSERT_EQUAL(1, h.GetRadius());
        ASSERT_EQUAL(0.5, h.GetStep());
    }
    {
        Helix h(10, 1);
        ASSERT_EQUAL("Helix", h.GetType());
    }
    {
        Helix h(1, 2);

        Point3D expected{1, 0, 0};
        ASSERT_EQUAL(expected, h.GetPoint(0));

        expected = Point3D{-1, 0, 2 * PI};
        ASSERT_EQUAL(expected, h.GetPoint(PI))

        expected = Point3D{0, 1, 2 * (PI / 2)};
        ASSERT_EQUAL(expected, h.GetPoint(PI/2));

        expected = Point3D{0, -1, 2 * ((3 * PI) / 2)};
        ASSERT_EQUAL(expected, h.GetPoint((3*PI)/2));
    }
    {
        Helix h(1, 2);

        Vector3D expected{0, 1, 2};
        ASSERT_EQUAL(expected, h.GetDerivative(0));

        expected = Vector3D{0, -1, 2};
        ASSERT_EQUAL(expected, h.GetDerivative(PI))

        expected = Vector3D{-1, 0, 2};
        ASSERT_EQUAL(expected, h.GetDerivative((PI)/2));

        expected = Vector3D{1, 0, 2};
        ASSERT_EQUAL(expected, h.GetDerivative((3*PI)/2));
    }
}