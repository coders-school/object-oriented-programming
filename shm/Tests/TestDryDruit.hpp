#pragma once

#include "../DryFruit.hpp"

TEST_CASE("Compare DryFruit to CargoDefault with same name", "[DryFruit][CargoDefault]") {
    auto dryFruit = generateCargo(dryFruitIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    REQUIRE(!(*dryFruit == *cargoDefault));
}

TEST_CASE("Compare CargoDefault to DryFruit with same name", "[DryFruit][CargoDefault]") {
    auto dryFruit = generateCargo(dryFruitIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    REQUIRE(!(*cargoDefault == *dryFruit));
}

TEST_CASE("Compare Fruit to DryFruit with same name", "[Fruit][DryFruit]") {
    auto fruit = generateCargo(fruitIndex, defaultGoodsName);
    auto dryFruit = generateCargo(dryFruitIndex, defaultGoodsName);

    REQUIRE(!(*fruit == *dryFruit));
}

TEST_CASE("Compare DryFruit to Fruit with same name", "[Fruit][DryFruit]") {
    auto fruit = generateCargo(fruitIndex, defaultGoodsName);
    auto dryFruit = generateCargo(dryFruitIndex, defaultGoodsName);

    REQUIRE(!(*dryFruit == *fruit));
}

//DryFruit::operator-- test

constexpr auto dryFruitValueMultipler = 3;
constexpr auto dryFruitRottingDivider = 10;

TEST_CASE("DryFruit decrement price over time", "[DryFruit]") {
    auto dryFruit = generateCargo(dryFruitIndex);
    auto& dryFruitTypeRef = dynamic_cast<DryFruit&>(*dryFruit);

    auto fruitValueFunct = [](auto daysPassed) -> size_t {
        size_t price = static_cast<size_t>(
            static_cast<double>(singleCargoCost * dryFruitValueMultipler                    //value of dry fruit
                                * (fruitBestBefore - daysPassed / dryFruitRottingDivider))  //days left
            / static_cast<double>(fruitBestBefore));                                        //max days
        if (daysPassed / dryFruitRottingDivider <= fruitBestBefore) {
            price = std::max(price, 1ul);  //minimal value for not rotten fruit
        }
        return price;
    };

    std::cout << "Dry fruit value: " << dryFruit->getPrice() << '\n';
    REQUIRE(dryFruit->getPrice() == singleCargoCost * dryFruitValueMultipler);

    for (size_t daysPassed = 1; daysPassed < fruitBestBefore * dryFruitRottingDivider; ++daysPassed) {
        --dryFruitTypeRef;
        std::cout << "Dry fruit value: " << dryFruit->getPrice() << '\n';
        REQUIRE(dryFruit->getPrice() == fruitValueFunct(daysPassed));
    }
}

TEST_CASE("DryFruit decrement below max time", "[DryFruit]") {
    auto dryFruit = generateCargo(dryFruitIndex);
    auto& dryFruitTypeRef = dynamic_cast<DryFruit&>(*dryFruit);

    for (size_t daysPassed = 1; daysPassed < fruitBestBefore * dryFruitRottingDivider; ++daysPassed) {
        --dryFruitTypeRef;
        REQUIRE(dryFruit->getPrice() > 0);
    }
    constexpr auto rottingDays = 4;
    for (size_t daysPassed = 0; daysPassed < rottingDays; ++daysPassed) {
        --dryFruitTypeRef;
        std::cout << "Dry fruit value after rotting: " << dryFruit->getPrice() << '\n';
        REQUIRE(dryFruit->getPrice() == 0);
    }
}

TEST_CASE("DryFruit with minimal value decrement below max time", "[DryFruit]") {
    auto dryFruit = std::make_unique<DryFruit>(goods[dryFruitIndex].name, fullQuantity, minimalCargoCost, fruitBestBefore);
    auto& dryFruitTypeRef = dynamic_cast<DryFruit&>(*dryFruit);

    std::cout << "Dry fruit value: " << dryFruit->getPrice() << '\n';
    for (size_t daysPassed = 1; daysPassed < fruitBestBefore * dryFruitRottingDivider; ++daysPassed) {
        --dryFruitTypeRef;
        std::cout << "Dry fruit value: " << dryFruit->getPrice() << '\n';
        REQUIRE(dryFruit->getPrice() > 0);
    }
    constexpr auto rottingDays = 4;
    for (int daysPassed = 0; daysPassed < rottingDays; ++daysPassed) {
        --dryFruitTypeRef;
        std::cout << "Dry fruit value after rotting: " << dryFruit->getPrice() << '\n';
        REQUIRE(dryFruit->getPrice() == 0);
    }
}
