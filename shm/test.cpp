#include <vector>

#include "Cargo.hpp"
#include "Island.hpp"
#include "gtest/gtest.h"

TEST(cargo, TwoCargosWithTheSameAmountShouldBeEqual)
{
    Cargo cargoA, cargoB;
    cargoA += 10;
    cargoB += 10;
    ASSERT_EQ(cargoA, cargoB);
}

TEST(cargo, TwoCargosWithDifferentAmountShouldNotBeEqual)
{
    Cargo cargoA, cargoB;
    cargoA += 10;
    cargoB += 100;
    ASSERT_NE(cargoA, cargoB);
}

TEST(cargo, TwoCargosWithDifferentAmountShouldNotBeEqualWithGetters)
{
    Cargo cargoA(10, 1), cargoB(100, 2);
    EXPECT_FALSE(cargoA.getAmount() == cargoB.getAmount());
    cargoA+=90;
    EXPECT_EQ(cargoA.getAmount(), cargoB.getAmount());
}
