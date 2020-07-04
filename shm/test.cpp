#include <vector>
#include <set>

#include "Cargo.hpp"
#include "Island.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "gtest/gtest.h"

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

TEST(island, twoIslandsPositionsShouldBeEqual)
{
    Island A(9, 9), B(9, 9);
    EXPECT_EQ(A.getPosition(), B.getPosition());
}

TEST(player, newSpaceWasSet)
{
    Ship ship;
    size_t space = 10;
    Player player(ship, 0, space);
    EXPECT_EQ(player.getAvailableSpace(), space);
}

TEST(player, newMoneyAmountWasSet)
{
    Ship ship;
    Player player(ship, 0, 0);
    size_t money = 10;
    player.setMoney(money);
    EXPECT_EQ(player.getMoney(), money);
}

TEST(map, mapWithOneIsland)
{
    Map map_(1, 1, 1);
    Island island_{Island(0, 0)};
    EXPECT_EQ(map_.getIslands().at(0).getPosition(), island_.getPosition());
}

TEST(map, mapWith10uniqueIslands)
{
    Map map_;
    std::vector<Island> islands = map_.getIslands();
    std::set<std::pair<int, int>> set_;
    for (auto& is : islands)
        set_.insert(std::make_pair(is.getPosition().position_x, is.getPosition().position_y));

    EXPECT_EQ(map_.getIslands().size(), set_.size());
}

TEST(map, getIslandShouldRTeturnIsland)
{
    Map map_;
    std::vector<Island> islands = map_.getIslands();
    Island island_ = islands[4];
    Coordinates corr = island_.getPosition();

    EXPECT_EQ(map_.getIsland(corr).getPosition(), corr);
}

TEST(map, getIslandShouldRTeturnCorrectIsland)
{
    Map map_;
    std::vector<Island> islands = map_.getIslands();
    Island island_ = islands[4];
    Coordinates corr = islands[1].getPosition();

    EXPECT_NE(map_.getIsland(corr).getPosition(), island_.getPosition());
}
