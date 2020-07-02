#include "gtest/gtest.h"

#include "../island.hpp"

constexpr size_t testPositionX = 100;
constexpr size_t testPositionY = 200;

TEST(islandTest, ConstructorAndGettersTest) {
    Island islandTest(testPositionX, testPositionY);
    Island::Coordinates testCoordinates(testPositionX, testPositionY);

    auto coordinates = islandTest.getPosition();

    ASSERT_TRUE(coordinates == testCoordinates);
}
