#include "pch.h"
#include "gtest/gtest.h"

#include "Point3D.h"

TEST(Point3DTest, DefaultConstructor) {
    Point3D point;
    EXPECT_FLOAT_EQ(point.x(), 0.0f);
    EXPECT_FLOAT_EQ(point.y(), 0.0f);
    EXPECT_FLOAT_EQ(point.z(), 0.0f);
}

TEST(Point3DTest, ParameterizedConstructor) {
    Point3D point(1.0f, 2.0f, 3.0f);

    EXPECT_FLOAT_EQ(point.x(), 1.0f);
    EXPECT_FLOAT_EQ(point.y(), 2.0f);
    EXPECT_FLOAT_EQ(point.z(), 3.0f);
}

TEST(Point3DTest, SettersAndGetters) {
    Point3D point;
    point.setX(3.0f);
    point.setY(4.0f);
    point.setZ(5.0f);

    EXPECT_FLOAT_EQ(point.x(), 3.0f);
    EXPECT_FLOAT_EQ(point.y(), 4.0f);
    EXPECT_FLOAT_EQ(point.z(), 5.0f);
}

// Add more tests as needed for other functionality of the Point3D class.

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
