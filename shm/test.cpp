#include <vector>
#include <set>

#include "Cargo.hpp"
#include "Island.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "ShmExceptions.hpp"
#include "Time.hpp"
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

TEST(island, twoIslandsPositionsShouldBeEqual)
{
    Island A(9, 9), B(9, 9);
    EXPECT_EQ(A.getPosition(), B.getPosition());
}

TEST(player, newSpaceWasSet)
{
    size_t space_ = 10;
    size_t money_ = 1;
    Player player(std::make_unique<Ship>(), money_, space_);
    EXPECT_EQ(player.getAvailableSpace(), space_);
}

TEST(player, moneyShouldBeIncreasedAfterErn)
{
    size_t space_ = 10;
    size_t money_ = 1;
    Player player(std::make_unique<Ship>(), money_, space_);
    size_t moreMoney_ = 100;
    player.earnMoney(moreMoney_);
    EXPECT_EQ(player.getMoney(), money_ + moreMoney_);
}

TEST(player, moneyShouldBeDecreasedAfterSpend)
{
    size_t space_ = 10;
    size_t money_ = 1000;
    Player player(std::make_unique<Ship>(), money_, space_);
    size_t spentMoney_ = 100;
    player.spendMoney(spentMoney_);
    EXPECT_EQ(player.getMoney(), money_ - spentMoney_);
}

TEST(player, spendMoreMoneyThanHaveShouldResultException)
{
    size_t space_ = 10;
    size_t money_ = 100;
    Player player(std::make_unique<Ship>(), money_, space_);
    size_t spentMoney_ = 1000;
   EXPECT_THROW(player.spendMoney(spentMoney_), AmountException);
}

TEST(ship, crewShouldBeZero)
{
    Ship ship{1, 1, 1, "a", 1};
    EXPECT_THROW(ship.operator-=(10), AmountException);
}

TEST(ship, crewShouldNotBeHigherThanMaxCrew)
{
    Ship ship{1, 1, 1, "a", 1};
    EXPECT_THROW(ship.operator+=(10), AmountException);
}

TEST(player, newMoneyAmountWasSet)
{
    size_t space_ = 0;
    size_t money_ = 0;
    Player player(std::make_unique<Ship>(), money_, space_);
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
    Map map_{};
    std::vector<Island> islands = map_.getIslands();
    Island island_ = islands[4];
    Coordinates corr = islands[1].getPosition();

    EXPECT_NE(map_.getIsland(corr).getPosition(), island_.getPosition());
}

TEST(map, getIslandShouldReturnNegativeValueWhenIslandNotFound)
{
    Map map_{};
    Coordinates corr{-1, -1};
    EXPECT_EQ(map_.getIsland(corr).getPosition(), corr);
}

TEST(map, mapWithTooManyIslandsShouldThroException)
{
    EXPECT_THROW(Map(1, 1, 100), AmountException);
}

TEST(map, emptyTestAddExpectCallHere)
{
}
