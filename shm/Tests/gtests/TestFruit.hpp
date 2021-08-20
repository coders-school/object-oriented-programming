#pragma once

#include "Fruit.hpp"
#include "DefaultCargo.hpp"

TEST(Fruit, Compare_Fruit_to_CargoDefault_with_same_name) {
    auto fruit = generateCargo(fruitIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    EXPECT_TRUE(!(*fruit == *cargoDefault));
}

TEST(Fruit, Compare_CargoDefault_to_Fruit_with_same_name) {
    auto fruit = generateCargo(fruitIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    EXPECT_TRUE(!(*cargoDefault == *fruit));
}

//Fruit::operator-- test

TEST(Fruit, Fruit_decrement_price_over_time) {
    auto fruit = generateCargo(fruitIndex);
    auto& fruitTypeRef = dynamic_cast<Fruit&>(*fruit);

    auto fruitValueFunct = [](auto daysPassed) -> size_t {
        size_t price = static_cast<size_t>(
            static_cast<double>(singleCargoCost * (fruitBestBefore - daysPassed)) / static_cast<double>(fruitBestBefore));
        if (daysPassed <= fruitBestBefore) {
            price = std::max<size_t>(price, 1ul);  //minimal value for not rotten fruit
        }
        return price;
    };

    std::cout << "Fresh fruit value: " << fruit->getPrice() << '\n';
    EXPECT_TRUE(fruit->getPrice() == singleCargoCost);

    for (size_t daysPassed = 1; daysPassed < fruitBestBefore; ++daysPassed) {
        --fruitTypeRef;
        std::cout << "Fruit value: " << fruit->getPrice() << '\n';
        EXPECT_TRUE(fruit->getPrice() == fruitValueFunct(daysPassed));
    }
}

TEST(Fruit, Fruit_decrement_below_max_time) {
    auto fruit = generateCargo(fruitIndex);
    auto& fruitTypeRef = dynamic_cast<Fruit&>(*fruit);

    for (size_t daysPassed = 1; daysPassed < fruitBestBefore; ++daysPassed) {
        --fruitTypeRef;
    }
    constexpr auto rottingDays = 4;
    for (int daysPassed = 0; daysPassed < rottingDays; ++daysPassed) {
        --fruitTypeRef;
        std::cout << "Fruit value after rotting: " << fruit->getPrice() << '\n';
        EXPECT_TRUE(fruit->getPrice() == 0);
    }
}
