#include <vector>
#include <set>

#include "Island.hpp"
#include "Map.hpp"
#include "ShmExceptions.hpp"
#include "Time.hpp"
#include "gtest/gtest.h"

TEST(island, twoIslandsPositionsShouldBeEqual)
{
    Island A(9, 9), B(9, 9);
    EXPECT_EQ(A.getPosition(), B.getPosition());
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
