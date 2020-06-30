#include "gtest/gtest.h"

#include "../item.hpp"

#include <string>

const std::string testName = "Sword Of Destiny";
constexpr size_t testAmount = 200;
constexpr size_t testBasePrice = 40;
constexpr Item::Rarity testRarity = Item::Rarity::legendary;

TEST(itemTest, ConstructorAndGettersTest) {
    Item itemTest(testName, testAmount, testBasePrice, testRarity);

    ASSERT_EQ(itemTest.getName(), testName);
    ASSERT_EQ(itemTest.getAmount(), testAmount);
    ASSERT_TRUE(itemTest.getPrice() > testBasePrice);
}
