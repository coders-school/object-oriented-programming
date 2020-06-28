#include <vector>
#include <set>

#include "Cargo.hpp"
#include "Island.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "Map.hpp"
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
    Item itemA(10, "itemA", 1, Item::Rarity::common), cargoB(100, "itemB", 2, Item::Rarity::common);
    EXPECT_FALSE(itemA.GetAmount() == cargoB.GetAmount());
    itemA += 90;
    EXPECT_EQ(itemA.GetAmount(), cargoB.GetAmount());
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
