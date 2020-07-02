#include "gtest/gtest.h"
#include "cargo.hpp"
#include "item.hpp"

#include <string>

class ItemTest : public ::testing::Test {
public:
    Item::Rarity rarity = Item::Rarity::rare;

protected:
    std::string name = "Old_Shoe";
    size_t amount = 2;
    size_t basePrice = 1000;

    ItemTest() : itemOne(name, amount, basePrice, rarity) {}
    Item itemOne;
};


TEST_F(ItemTest, ShouldGivePriceOfItem) {
    auto priceAfterRarity = itemOne.getBasePrice() * static_cast<int>(rarity);
    ASSERT_EQ(itemOne.getPrice(), priceAfterRarity);
}
