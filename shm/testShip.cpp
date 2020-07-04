#include <string>

#include "gtest/gtest.h"
#include "ship.hpp"

class ShipTest : public ::testing::Test {
protected:
    std::string name = "First_Ship";
    size_t maxCrewOfShip = 30;
    size_t maxCargoCapacity = 100;
    size_t speedOfShip = 10;
    size_t idOfShip = 1;

    ShipTest() : shipOne(maxCargoCapacity, maxCrewOfShip, speedOfShip, name, idOfShip) {}
    Ship shipOne;
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
