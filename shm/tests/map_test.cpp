#include "gtest/gtest.h"

#include "../map.hpp"

#include <algorithm>

TEST(mapTest, ConstructorAndGettersTest) {
    Map mapTest;

    auto testIslands = mapTest.getIslands_();

    ASSERT_EQ(testIslands.size(), totalIslands);

    ASSERT_TRUE(std::all_of(std::begin(testIslands),
                            std::end(testIslands),
                            [](const auto& island) {
                                return (island.getPosition().getPositionX() <= mapWidth) &&
                                       (island.getPosition().getPositionY() <= mapHeight);
                            }));
}
