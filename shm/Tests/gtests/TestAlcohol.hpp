#pragma once

#include "Alcohol.hpp"
#include "DefaultCargo.hpp"

constexpr auto maxPercentage = 96;
constexpr size_t alcoholPriceFor96percent = 100u;

TEST(Alcohol, Value_of_Alcohol_with_0_percentage) {
    const auto percentage = 0;
    auto alcohol = std::make_unique<Alcohol>(defaultGoodsName, fullQuantity, percentage);
    EXPECT_TRUE(alcohol->getPrice() == minimalCargoCost);
}

TEST(Alcohol, Value_of_Alcohol_with_40_percentage) {
    const auto percentage = 40;
    auto alcohol = std::make_unique<Alcohol>(defaultGoodsName, fullQuantity, percentage);
    EXPECT_TRUE(alcohol->getPrice() == (alcoholPriceFor96percent*percentage/96));
}

TEST(Alcohol, Value_of_Alcohol_with_96_percentage) {
    const auto percentage = 96;
    auto alcohol = std::make_unique<Alcohol>(defaultGoodsName, fullQuantity, percentage);
    EXPECT_TRUE(alcohol->getPrice() == alcoholPriceFor96percent);
}

TEST(Alcohol, Value_of_Alcohol_with_100_percentage) {
    const auto percentage = 100;
    auto alcohol = std::make_unique<Alcohol>(defaultGoodsName, fullQuantity, percentage);
    EXPECT_TRUE(alcohol->getPrice() == alcoholPriceFor96percent);
}

TEST(Alcohol, Value_of_Alcohol_with_255_percentage) {
    const auto percentage = 255;
    auto alcohol = std::make_unique<Alcohol>(defaultGoodsName, fullQuantity, percentage);
    EXPECT_TRUE(alcohol->getPrice() == alcoholPriceFor96percent);
}

TEST(Alcohol, Compare_Alcohol_to_CargoDefault_with_same_name) {
    auto alcohol = generateCargo(alcoholIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    EXPECT_TRUE(!(*alcohol == *cargoDefault));
}

TEST(Alcohol, Compare_CargoDefault_to_Alcohol_with_same_name) {
    auto alcohol = generateCargo(alcoholIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    EXPECT_TRUE(!(*cargoDefault == *alcohol));
}