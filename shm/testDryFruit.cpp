#include <string>

#include "dryFruit.hpp"
#include "gtest/gtest.h"
#include "timeSHM.cpp"

class DryFruitTest : public ::testing::Test {
public:

protected:
    std::string name = "Apple";
    size_t amount = 100;
    size_t basePrice = 15;
    size_t expiryDate = 3;
    size_t timeElapsed = 1;
    Time Publisher;
    DryFruitTest() : fruitOne(name, amount, basePrice, expiryDate, timeElapsed, &Publisher) {
    };
    DryFruit fruitOne;
};


TEST_F(DryFruitTest, ShouldGivePriceOfItem) {
    ASSERT_EQ(fruitOne.getName(), "Dry Apple");
    ASSERT_EQ(fruitOne.getExpiryDate(), 3);
    ASSERT_EQ(fruitOne.getTimeElapsed(), 1);
    ASSERT_EQ(fruitOne.getPrice(), 30);
    fruitOne.nextDay();
    ASSERT_EQ(fruitOne.getPrice(), 30);
    for(size_t i = 0; i < 9;i++){
        fruitOne.nextDay();
    }
    ASSERT_EQ(fruitOne.getTimeElapsed(), 2);
    ASSERT_EQ(fruitOne.getPrice(), 15);
}
