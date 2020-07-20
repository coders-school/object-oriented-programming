#include <vector>
#include <set>

#include "Cargo.hpp"
#include "Island.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "ShmExceptions.hpp"
#include "gtest/gtest.h"

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
