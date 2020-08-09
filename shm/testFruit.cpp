
#include "Cargo.hpp"
#include "Fruit.hpp"
#include "gtest/gtest.h"

TEST(fruit, GetDescriptionReturnFullStringForApple)
{
    size_t amount = 10;
    std::string name = "Apple";
    size_t base_price = 2;
    size_t expiry_date = 7;
    size_t time_elapsed = 2;
    Fruit apple(amount, name, base_price, expiry_date, time_elapsed);
    EXPECT_EQ(apple.GetDescription(), "Name: Apple Amount: 10 Price: 20 Expiry date: 7");
}