
#include "Cargo.hpp"
#include "Item.hpp"
#include "gtest/gtest.h"

TEST(item, TwoItemsWithTheSameAmountShouldBeEqual)
{
    size_t amount{10};
    Item itemA{amount, "item", 0, Item::Rarity::common}, itemB{amount, "item", 0, Item::Rarity::common};
    itemA += 10;
    itemB += 10;
    ASSERT_EQ(itemA, itemB);
}

TEST(item, TwoItemssWithDifferentAmountShouldNotBeEqual)
{
    Item itemA{0, "itemA", 0, Item::Rarity::common}, itemB{0, "itemB", 0, Item::Rarity::common};
    itemA += 10;
    itemB += 100;
    ASSERT_NE(itemA, itemB);
}

TEST(item, TwoItemsWithDifferentAmountShouldNotBeEqualWithGetters)
{
    Item itemA(10, "itemA", 1, Item::Rarity::common), itemB(100, "itemB", 2, Item::Rarity::common);
    EXPECT_FALSE(itemA.GetAmount() == itemB.GetAmount());
    itemA += 90;
    EXPECT_EQ(itemA.GetAmount(), itemB.GetAmount());
}

TEST(item, TwoIdenticalItemsShouldBeEqualWithEqualOperator)
{
    Item itemA(10, "item", 1, Item::Rarity::common), itemB(10, "item", 1, Item::Rarity::common);
    EXPECT_TRUE(itemA == itemB);
    EXPECT_FALSE(itemA != itemB);
}

TEST(item, TwoIdenticalItemsWithDifferenAmountShouldBeNotEqualWithEqualOperator)
{
    Item itemA(100, "item", 1, Item::Rarity::common), itemB(10, "item", 1, Item::Rarity::common);
    EXPECT_FALSE(itemA == itemB);
    EXPECT_TRUE(itemA != itemB);
}

TEST(item, TwoIdenticalItemsWithDifferenNameShouldBeNotEqualWithEqualOperator)
{
    Item itemA(10, "itemA", 1, Item::Rarity::common), itemB(10, "itemB", 1, Item::Rarity::common);
    EXPECT_FALSE(itemA == itemB);
    EXPECT_TRUE(itemA != itemB);
}

TEST(item, TwoIdenticalItemsWithDifferenBasePriceShouldBeNotEqualWithEqualOperator)
{
    Item itemA(10, "item", 10, Item::Rarity::common), itemB(10, "item", 1, Item::Rarity::common);
    EXPECT_FALSE(itemA == itemB);
    EXPECT_TRUE(itemA != itemB);
}

TEST(item, TwoIdenticalItemsWithDifferenRarityShouldBeNotEqualWithEqualOperator)
{
    Item itemA(10, "item", 1, Item::Rarity::epic), itemB(10, "item", 1, Item::Rarity::common);
    EXPECT_FALSE(itemA == itemB);
    EXPECT_TRUE(itemA != itemB);
}

TEST(item, TwoItemsWithDifferentAmountShouldNotBeEqualWithEqualOperator)
{
    Item itemA(10, "item", 10, Item::Rarity::common), itemB(100, "item", 10, Item::Rarity::common);
    EXPECT_FALSE(itemA == itemB);
    EXPECT_TRUE(itemA != itemB);
}

TEST(item, TwoItemsWithDifferentAllPropertiesShouldNotBeEqualWithEqualOperator)
{
    Item itemA(10, "itemA", 1, Item::Rarity::common), itemB(100, "itemB", 2, Item::Rarity::legendary);
    EXPECT_FALSE(itemA == itemB);
    EXPECT_TRUE(itemA != itemB);
}

TEST(item, GetRarityShouldReturnProperValue)
{
    Item itemA(10, "item", 1, Item::Rarity::rare);
    EXPECT_EQ(itemA.GetRarity(), Item::Rarity::rare);
}

TEST(item, SubstractFromOperatorSubstractAmount)
{
    Item itemA(10, "item", 1, Item::Rarity::rare);
    itemA -= 5;
    EXPECT_EQ(itemA.GetAmount(), 5);
}

TEST(item, AddToOperatorIncreaseAmount)
{
    Item itemA(10, "item", 1, Item::Rarity::rare);
    itemA += 5;
    EXPECT_EQ(itemA.GetAmount(), 15);
}


