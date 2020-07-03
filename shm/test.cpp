#include "cargo.hpp"
#include "coordinates.hpp"
#include "island.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"

#include <vector>
#include "gtest/gtest.h"

class SHM_TestFixture : public ::testing::Test {
public:
    SHM_TestFixture() {
        // initialization code here
    }

    void SetUp() {
        // code here will execute just before the test ensues
    }

    void TearDown() {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

    ~SHM_TestFixture() {
        // cleanup any pending stuff, but no exceptions allowed
    }

    // put in any custom data members that you need
    Map testMap;
};

TEST_F(SHM_TestFixture, ShouldAlwaysPass) {
    EXPECT_TRUE(true);
}

TEST_F(SHM_TestFixture, ShouldReturnNullPtrWhenAskedForIslandOutOfRange) {
    Coordinates location(MAP_RND_DISTRIBUTION_MAX + 10, MAP_RND_DISTRIBUTION_MAX + 10);
    EXPECT_EQ(nullptr, testMap.getIsland(location));
}
