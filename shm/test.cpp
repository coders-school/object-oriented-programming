
#include <iostream>
#include "Cargo.hpp"
#include "Fruit.hpp"
#include "ShmExceptions.hpp"
#include "Time.hpp"
#include "gtest/gtest.h"

TEST(cargo, FruitsSpoilWhenDayPasses)
{
    size_t time_elapsed = 0;
    size_t expiry_date = 2;
    size_t amount = 2;
    size_t price = 1;

    Fruit fruit{amount, "japko", price, expiry_date, time_elapsed};
    fruit.NextDay();
    EXPECT_EQ(fruit.GetAmount(), 2);
    fruit.NextDay();
    EXPECT_EQ(fruit.GetAmount(), 0);
}
