#include "Coordinates.h"
#include "gtest/gtest.h"

Coordinates coord(1, 1);

TEST(SHMShipTest, createShip) {
    Coordinates testCoord(1, 1);
    EXPECT_EQ(testCoord.distance(testCoord, coord), 0);
}
