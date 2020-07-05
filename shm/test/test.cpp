#include "gtest/gtest.h"

#include "fruit.hpp"
#include "ship.hpp"
#include "store.hpp"

constexpr int SHIP_MAX_CREW = 20;
constexpr int SHIP_SPEED = 666;
constexpr size_t SHIP_ID = 7;

TEST(ShipTest, ShouldInitShip) {
    Ship ship(SHIP_MAX_CREW, SHIP_SPEED, SHIP_ID);
    EXPECT_EQ(ship.getMaxCrew(), SHIP_MAX_CREW);
    EXPECT_EQ(ship.getSpeed(), SHIP_SPEED);
    EXPECT_EQ(ship.getId(), SHIP_ID);
}
TEST(StreamTest, ShoutOutputStore) {
    Store store;
    Fruit fruit("apple", 50, 8, 99);
    store.addCargo(&fruit);

    std::cout << store;
}
