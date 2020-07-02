#include "gtest/gtest.h"

#include "../ship.hpp"

constexpr int testCapacity = 100;
constexpr int testMaxCrew = 200;
constexpr int testSpeed = 50;
const std::string testName = "testShip";
constexpr size_t testId = 20;

TEST(shipTest, ConstructorAndGettersTest) {
    Ship testShip;
    ASSERT_EQ(testShip.getCapacity(), 0);
    ASSERT_EQ(testShip.getMaxCrew(), 0);
    ASSERT_EQ(testShip.getSpeed(), 0);
    ASSERT_EQ(testShip.getName(), "");
    ASSERT_EQ(testShip.getId(), 0);

    Ship testShip2(testMaxCrew, testSpeed, testId);

    ASSERT_EQ(testShip2.getMaxCrew(), testMaxCrew);
    ASSERT_EQ(testShip2.getSpeed(), testSpeed);
    ASSERT_EQ(testShip2.getId(), testId);
    ASSERT_EQ(testShip2.getName(), "");
    ASSERT_EQ(testShip2.getCapacity(), 0);

    Ship testShip3(testMaxCrew, testSpeed, testId, testName, testCapacity);
    ASSERT_EQ(testShip3.getMaxCrew(), testMaxCrew);
    ASSERT_EQ(testShip3.getSpeed(), testSpeed);
    ASSERT_EQ(testShip3.getId(), testId);
    ASSERT_EQ(testShip3.getName(), testName);
    ASSERT_EQ(testShip3.getCapacity(), testCapacity);
}
