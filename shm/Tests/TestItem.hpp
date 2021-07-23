#pragma once

#include "../Cargos/DefaultCargo.hpp"
#include "../Cargos/Item.hpp"

constexpr auto commonQualityValue = 80;
constexpr auto rareQualityValue = 100;
constexpr auto epicQualityValue = 110;
constexpr auto legendaryQualityValue = 125;

TEST_CASE("Value of Item with quality common", "[Item]") {
    auto item = std::make_unique<Item>(defaultGoodsName, fullQuantity, singleCargoCost, Quality::common);
    REQUIRE(item->getPrice() == (singleCargoCost * commonQualityValue / 100));
}

TEST_CASE("Value of Item with quality rare", "[Item]") {
    auto item = std::make_unique<Item>(defaultGoodsName, fullQuantity, singleCargoCost, Quality::rare);
    REQUIRE(item->getPrice() == (singleCargoCost * rareQualityValue / 100));
}

TEST_CASE("Value of Item with quality epic", "[Item]") {
    auto item = std::make_unique<Item>(defaultGoodsName, fullQuantity, singleCargoCost, Quality::epic);
    REQUIRE(item->getPrice() == (singleCargoCost * epicQualityValue / 100));
}

TEST_CASE("Value of Item with quality legendary", "[Item]") {
    auto item = std::make_unique<Item>(defaultGoodsName, fullQuantity, singleCargoCost, Quality::legendary);
    REQUIRE(item->getPrice() == (singleCargoCost * legendaryQualityValue / 100));
}

TEST_CASE("Compare Item to CargoDefault with same name", "[Item][CargoDefault]") {
    auto item = generateCargo(itemIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    REQUIRE(!(*item == *cargoDefault));
}

TEST_CASE("Compare CargoDefault to Item with same name", "[Item][CargoDefault]") {
    auto item = generateCargo(itemIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    REQUIRE(!(*cargoDefault == *item));
}
