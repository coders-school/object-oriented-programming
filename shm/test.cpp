#include "Fruit.h"
#include "gtest/gtest.h"

std::string name_;
size_t amount_;
size_t basePrice_;
size_t time_elapsed_{0};
size_t expiry_date_;

std::string NAME = "Banan";
size_t AMOUNT = 4;
size_t BASE_PRICE = 10;
size_t EXPIRY_DATE_ = 3;
Time* TIME;

TEST(shmFruitTest, createFruit) {
    Fruit fruit(NAME, AMOUNT, BASE_PRICE, TIME, EXPIRY_DATE_);
    EXPECT_EQ(fruit.getName(), NAME);
    EXPECT_EQ(fruit.getAmount(), AMOUNT);
    EXPECT_EQ(fruit.getBasePrice(), BASE_PRICE);
    EXPECT_EQ(fruit.getExpiryDate(), EXPIRY_DATE_);
}
