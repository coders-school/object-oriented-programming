#pragma once

#include "DefaultCargo.hpp"
#include "Item.hpp"

constexpr auto commonQualityValue = 80;
constexpr auto rareQualityValue = 100;
constexpr auto epicQualityValue = 110;
constexpr auto legendaryQualityValue = 125;

TEST(Item, Value_of_Item_with_quality_common) {
    auto item = std::make_unique<Item>(defaultGoodsName, fullQuantity, singleCargoCost, Quality::common);
    EXPECT_TRUE(item->getPrice() == (singleCargoCost * commonQualityValue / 100));
}

TEST(Item, Value_of_Item_with_quality_rare) {
    auto item = std::make_unique<Item>(defaultGoodsName, fullQuantity, singleCargoCost, Quality::rare);
    EXPECT_TRUE(item->getPrice() == (singleCargoCost * rareQualityValue / 100));
}

TEST(Item, Value_of_Item_with_quality_epic) {
    auto item = std::make_unique<Item>(defaultGoodsName, fullQuantity, singleCargoCost, Quality::epic);
    EXPECT_TRUE(item->getPrice() == (singleCargoCost * epicQualityValue / 100));
}

TEST(Item, Value_of_Item_with_quality_legendary) {
    auto item = std::make_unique<Item>(defaultGoodsName, fullQuantity, singleCargoCost, Quality::legendary);
    EXPECT_TRUE(item->getPrice() == (singleCargoCost * legendaryQualityValue / 100));
}

TEST(Item, Compare_Item_to_CargoDefault_with_same_name) {
    auto item = generateCargo(itemIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    EXPECT_TRUE(!(*item == *cargoDefault));
}

TEST(Item, Compare_CargoDefault_to_Item_with_same_name) {
    auto item = generateCargo(itemIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    EXPECT_TRUE(!(*cargoDefault == *item));
}
