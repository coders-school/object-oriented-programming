#include "coordinates.hpp"
#include "gtest/gtest.h"

TEST(CoordinatesTest, shouldCheckIfCoordsAreEqual) {
    Coordinates lhs(2, 4);
    Coordinates rhs(2, 4);
    EXPECT_EQ(lhs, rhs);
}

TEST(CoordinatesTest, shouldCountDistanceBetweenCoordsXAxis) {
    Coordinates lhs(2, 4);
    Coordinates rhs(5, 4);
    EXPECT_EQ(Coordinates::distance(lhs, rhs), 3);
}

TEST(CoordinatesTest, shouldCountDistanceBetweenCoordsYAxis) {
    Coordinates lhs(2, 4);
    Coordinates rhs(2, 2);
    EXPECT_EQ(Coordinates::distance(lhs, rhs), 2);
}

TEST(CoordinatesTest, shouldCountDistanceBetweenCoords) {
    Coordinates lhs(1, 4);
    Coordinates rhs(-2, 9);
    EXPECT_EQ(Coordinates::distance(lhs, rhs), 5);
}
