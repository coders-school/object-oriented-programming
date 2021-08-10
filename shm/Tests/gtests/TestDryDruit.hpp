#pragma once

#include "DryFruit.hpp"

TEST(DryFruit, Compare_DryFruit_to_CargoDefault_with_same_name) {
    auto dryFruit = generateCargo(dryFruitIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    EXPECT_TRUE(!(*dryFruit == *cargoDefault));
}

TEST(DryFruit, Compare_CargoDefault_to_DryFruit_with_same_name) {
    auto dryFruit = generateCargo(dryFruitIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    EXPECT_TRUE(!(*cargoDefault == *dryFruit));
}

TEST(DryFruit, Compare_Fruit_to_DryFruit_with_same_name) {
    auto fruit = generateCargo(fruitIndex, defaultGoodsName);
    auto dryFruit = generateCargo(dryFruitIndex, defaultGoodsName);

    EXPECT_TRUE(!(*fruit == *dryFruit));
}

TEST(DryFruit, Compare_DryFruit_to_Fruit_with_same_name) {
    auto fruit = generateCargo(fruitIndex, defaultGoodsName);
    auto dryFruit = generateCargo(dryFruitIndex, defaultGoodsName);

    EXPECT_TRUE(!(*dryFruit == *fruit));
}

//DryFruit::operator-- test

constexpr auto dryFruitValueMultipler = 3;
constexpr auto dryFruitRottingDivider = 10;

TEST(DryFruit, DryFruit_decrement_price_over_time) {
    auto dryFruit = generateCargo(dryFruitIndex);
    auto& dryFruitTypeRef = dynamic_cast<DryFruit&>(*dryFruit);

    auto fruitValueFunct = [](auto daysPassed) -> size_t {
        size_t price = static_cast<size_t>(
            static_cast<double>(singleCargoCost * dryFruitValueMultipler                    //value of dry fruit
                                * (fruitBestBefore - daysPassed / dryFruitRottingDivider))  //days left
            / static_cast<double>(fruitBestBefore));                                        //max days
        if (daysPassed / dryFruitRottingDivider <= fruitBestBefore) {
            price = std::max<size_t>(price, 1ul);  //minimal value for not rotten fruit
        }
        return price;
    };

    std::cout << "Dry fruit value: " << dryFruit->getPrice() << '\n';
    EXPECT_TRUE(dryFruit->getPrice() == singleCargoCost * dryFruitValueMultipler);

    for (size_t daysPassed = 1; daysPassed < fruitBestBefore * dryFruitRottingDivider; ++daysPassed) {
        --dryFruitTypeRef;
        std::cout << "Dry fruit value: " << dryFruit->getPrice() << '\n';
        EXPECT_TRUE(dryFruit->getPrice() == fruitValueFunct(daysPassed));
    }
}

TEST(DryFruit, DryFruit_decrement_below_max_time) {
    auto dryFruit = generateCargo(dryFruitIndex);
    auto& dryFruitTypeRef = dynamic_cast<DryFruit&>(*dryFruit);

    for (size_t daysPassed = 1; daysPassed < fruitBestBefore * dryFruitRottingDivider; ++daysPassed) {
        --dryFruitTypeRef;
        EXPECT_TRUE(dryFruit->getPrice() > 0);
    }
    constexpr auto rottingDays = 4;
    for (size_t daysPassed = 0; daysPassed < rottingDays; ++daysPassed) {
        --dryFruitTypeRef;
        std::cout << "Dry fruit value after rotting: " << dryFruit->getPrice() << '\n';
        EXPECT_TRUE(dryFruit->getPrice() == 0);
    }
}

TEST(DryFruit, DryFruit_with_minimal_value_decrement_below_max_time) {
    auto dryFruit = std::make_unique<DryFruit>(goods[dryFruitIndex].name, fullQuantity, minimalCargoCost, fruitBestBefore);
    auto& dryFruitTypeRef = dynamic_cast<DryFruit&>(*dryFruit);

    std::cout << "Dry fruit value: " << dryFruit->getPrice() << '\n';
    for (size_t daysPassed = 1; daysPassed < fruitBestBefore * dryFruitRottingDivider; ++daysPassed) {
        --dryFruitTypeRef;
        std::cout << "Dry fruit value: " << dryFruit->getPrice() << '\n';
        EXPECT_TRUE(dryFruit->getPrice() > 0);
    }
    constexpr auto rottingDays = 4;
    for (int daysPassed = 0; daysPassed < rottingDays; ++daysPassed) {
        --dryFruitTypeRef;
        std::cout << "Dry fruit value after rotting: " << dryFruit->getPrice() << '\n';
        EXPECT_TRUE(dryFruit->getPrice() == 0);
    }
}
