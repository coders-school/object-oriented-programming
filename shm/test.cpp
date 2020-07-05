#include "gtest/gtest.h"
#include "Ship.hpp"

size_t CAPACITY = 1000;
size_t CREW = 20;
size_t SPEED = 500;
std::string NAME = "Czarna";
size_t ID = 7;

TEST(SHMShipTest, createShip) {
    Ship ship(CAPACITY, CREW, SPEED, NAME, ID);
    EXPECT_EQ(ship.getCapacity(), CAPACITY);
    EXPECT_EQ(ship.getMaxCrew(), CREW);
    EXPECT_EQ(ship.getSpeed(), SPEED);
    EXPECT_EQ(ship.getName(), NAME);
    EXPECT_EQ(ship.getId(), ID);
}
