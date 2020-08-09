
#include "Cargo.hpp"
#include "Alcohol.hpp"
#include "gtest/gtest.h"

TEST(alcohol, GetDescriptionReturnFullStringForVodka)
{
    size_t amount = 100;
    std::string name = "Vodka";
    size_t base_price = 5;
    size_t percentage = 40;
    Alcohol alcohol(amount, name, base_price, percentage);
    EXPECT_EQ(alcohol.GetDescription(), "Name: Vodka Amount: 100 Price: 500 Percentage: 40");
}
