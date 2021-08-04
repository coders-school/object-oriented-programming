#pragma once

#include "Fruit.hpp"
#include "DefaultCargo.hpp"

TEST_CASE("Compare Fruit to CargoDefault with same name", "[Fruit][CargoDefault]") {
    auto fruit = generateCargo(fruitIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    REQUIRE(!(*fruit == *cargoDefault));
}

TEST_CASE("Compare CargoDefault to Fruit with same name", "[Fruit][CargoDefault]") {
    auto fruit = generateCargo(fruitIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    REQUIRE(!(*cargoDefault == *fruit));
}

//Fruit::operator-- test

TEST_CASE("Fruit decrement price over time", "[Fruit]") {
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
    REQUIRE(fruit->getPrice() == singleCargoCost);

    for (size_t daysPassed = 1; daysPassed < fruitBestBefore; ++daysPassed) {
        --fruitTypeRef;
        std::cout << "Fruit value: " << fruit->getPrice() << '\n';
        REQUIRE(fruit->getPrice() == fruitValueFunct(daysPassed));
    }
}

TEST_CASE("Fruit decrement below max time", "[Fruit]") {
    auto fruit = generateCargo(fruitIndex);
    auto& fruitTypeRef = dynamic_cast<Fruit&>(*fruit);

    for (size_t daysPassed = 1; daysPassed < fruitBestBefore; ++daysPassed) {
        --fruitTypeRef;
    }
    constexpr auto rottingDays = 4;
    for (int daysPassed = 0; daysPassed < rottingDays; ++daysPassed) {
        --fruitTypeRef;
        std::cout << "Fruit value after rotting: " << fruit->getPrice() << '\n';
        REQUIRE(fruit->getPrice() == 0);
    }
}
