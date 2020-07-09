#include <string>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "gtest/gtest.h"
#include "item.hpp"

struct TestCargo : public ::testing::Test {
    Alcohol alcohol = Alcohol("whisky", 10, 110, 0.40);
    Fruit fruit = Fruit("apple", 50, 2, 30);
    Item::Rarity rarity = Item::Rarity::legendary;
    Item item = Item("ContinouumTransfunctioner", 1, 1000000, rarity);
};

TEST_F(TestCargo, checkAlcoholConstructor) {
    ASSERT_EQ(alcohol.getBasePrice(), 110);
    ASSERT_EQ(alcohol.getName(), "whisky");
    ASSERT_EQ(alcohol.getAmount(), 10);
    ASSERT_EQ(alcohol.getVolume(), 0.40);
}

TEST_F(TestCargo, checkAlcoholOperator) {
    alcohol += 5;
    ASSERT_EQ(alcohol.getAmount(), 15);
    alcohol -= 2;
    ASSERT_EQ(alcohol.getAmount(), 13);
    Alcohol alcohol2 = Alcohol("whisky", 13, 110, 0.40);
    ASSERT_TRUE(alcohol == alcohol2);
}

TEST_F(TestCargo, checkFruitConstructor) {
    ASSERT_EQ(fruit.getBasePrice(), 2);
    ASSERT_EQ(fruit.getName(), "apple");
    ASSERT_EQ(fruit.getAmount(), 50);
    ASSERT_EQ(fruit.getTimeToRotten(), 30);
}

TEST_F(TestCargo, checkFruitOperator) {
    //--fruit;
    fruit += 10;
    ASSERT_EQ(fruit.getAmount(), 60);
    fruit += 2;
    ASSERT_EQ(fruit.getAmount(), 62);
    fruit -= 5;
    ASSERT_EQ(fruit.getAmount(), 57);
    Fruit fruit2 = Fruit("apple", 50, 1.5, 30);
    ASSERT_FALSE(fruit == fruit2);
}

TEST_F(TestCargo, checkItemConstructor) {
    ASSERT_EQ(item.getBasePrice(), 1000000);
    ASSERT_EQ(item.getName(), "ContinouumTransfunctioner");
    ASSERT_EQ(item.getAmount(), 1);
    ASSERT_EQ(item.enumToString(item.getRarity()), "legendary");
    Item item2 = Item("ContinouumTransfunctioner", 1, 1000000, rarity);
    ASSERT_TRUE(item == item2);
}

TEST_F(TestCargo, checkItemOperator) {
    item += 1;
    ASSERT_EQ(item.getAmount(), 2);
    item -= 1;
    ASSERT_EQ(item.getAmount(), 1);
}
