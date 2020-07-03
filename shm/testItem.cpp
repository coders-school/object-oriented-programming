#include "gtest/gtest.h"
#include "cargo.hpp"
#include "item.hpp"
#include "rarity.hpp"
#include <string>
#include "timeSHM.cpp"
class ItemTest : public ::testing::Test {
public:
   int rarity = static_cast<int>(Rarity::rare);

protected:
    std::string name = "Old_Shoe";
    size_t amount = 2;
    size_t basePrice = 1000;
    Time Publisher;
    ItemTest() : itemOne(name, amount, basePrice, rarity, &Publisher) {};
    Item itemOne;
};


TEST_F(ItemTest, ShouldGivePriceOfItem) {
    auto priceAfterRarity = itemOne.getBasePrice() * rarity;
    ASSERT_EQ(itemOne.getPrice(), priceAfterRarity);
}
