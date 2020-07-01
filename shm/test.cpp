#include "gtest/gtest.h"
#include "cargo.hpp"
#include "item.hpp"
#include "ship.hpp"

#include <string>

class ShipTest : public ::testing::Test {
protected:
    std::string name = "First_Ship";
    size_t maxCrewOfShip = 30;
    size_t maxCargoCapacity = 100;

    ShipTest() : shipOne(maxCargoCapacity, maxCrewOfShip, 10, name, 1) {}
    Ship shipOne;
};

class ItemTest : public ::testing::Test {
public:
    Item::Rarity rarity = Item::Rarity::rare;

protected:
    std::string name = "Old_Shoe";
    size_t amount = 2;
    size_t basePrice = 1000;

    ItemTest() : itemOne(name, amount, basePrice, rarity) {}
    Item itemOne;
};

TEST_F(ShipTest, ShouldChangeShipName) {
    shipOne.setName("Roaar");
    ASSERT_EQ(shipOne.getName(), "Roaar");
}

TEST_F(ShipTest, ShouldSubtractNewMembersFromShipCrew) {
    auto amountOfNewMembers = 2;
    shipOne += 20;
    auto amountOfActualCrew = shipOne.getCrew();
  
    shipOne -= amountOfNewMembers;
    ASSERT_EQ(shipOne.getCrew(), amountOfActualCrew - amountOfNewMembers);
}

TEST_F(ShipTest, ShouldNotSubtractNewMembersFromShipCrewBecauseOfTooSmallCrew) {
    auto amountOfNewMembers = 20;
    shipOne += 14;
    auto amountOfActualCrew = shipOne.getCrew();
  
    shipOne -= amountOfNewMembers;
    ASSERT_EQ(shipOne.getCrew(), amountOfActualCrew);
}

TEST_F(ShipTest, ShouldAddNewMembersToShipCrew) {
    auto amountOfNewMembers = 14;
    auto amountOfActualCrew = shipOne.getCrew(); //initial value = 0
  
    shipOne += amountOfNewMembers;
    ASSERT_EQ(shipOne.getCrew(), amountOfNewMembers + amountOfActualCrew);
}

TEST_F(ShipTest, ShouldNotAddNewMembersToShipCrewBecauseOfTooManyMembers) {
    auto amountOfNewMembers = 50;
    auto amountOfActualCrew = shipOne.getCrew();
  
    shipOne += amountOfNewMembers;
    ASSERT_EQ(shipOne.getCrew(), amountOfActualCrew);
}

TEST_F(ShipTest, ShouldCountAvailableCargoSpaceWhenShipHasNoCargoToSell) {
    ASSERT_EQ(shipOne.countAvailableSpace(), shipOne.getCapacity());
}

TEST_F(ItemTest, ShouldGivePriceOfItem) {
    auto priceAfterRarity = itemOne.getBasePrice() * static_cast<int>(rarity);
    ASSERT_EQ(itemOne.getPrice(), priceAfterRarity);
}