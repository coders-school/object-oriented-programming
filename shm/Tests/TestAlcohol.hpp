#pragma once

#include "../Cargos/Alcohol.hpp"
#include "../Cargos/DefaultCargo.hpp"

TEST_CASE("Value of Alcohol with 0 percentage", "[Item]") {
    const auto percentage = 0;
    auto alcohol = std::make_unique<Alcohol>(defaultGoodsName, fullQuantity, percentage);
    REQUIRE(alcohol->getPrice() == minimalCargoCost);
}

TEST_CASE("Value of Alcohol with 40 percentage", "[Item]") {
    const auto percentage = 40;
    auto alcohol = std::make_unique<Alcohol>(defaultGoodsName, fullQuantity, percentage);
    REQUIRE(alcohol->getPrice() == (alcoholPriceFor96percent*percentage/96));
}

TEST_CASE("Value of Alcohol with 96 percentage", "[Item]") {
    const auto percentage = 96;
    auto alcohol = std::make_unique<Alcohol>(defaultGoodsName, fullQuantity, percentage);
    REQUIRE(alcohol->getPrice() == alcoholPriceFor96percent);
}

TEST_CASE("Value of Alcohol with 100 percentage", "[Item]") {
    const auto percentage = 100;
    auto alcohol = std::make_unique<Alcohol>(defaultGoodsName, fullQuantity, percentage);
    REQUIRE(alcohol->getPrice() == alcoholPriceFor96percent);
}

TEST_CASE("Value of Alcohol with 255 percentage", "[Item]") {
    const auto percentage = 255;
    auto alcohol = std::make_unique<Alcohol>(defaultGoodsName, fullQuantity, percentage);
    REQUIRE(alcohol->getPrice() == alcoholPriceFor96percent);
}

TEST_CASE("Compare Alcohol to CargoDefault with same name", "[Alcohol][CargoDefault]") {
    auto alcohol = generateCargo(alcoholIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    REQUIRE(!(*alcohol == *cargoDefault));
}

TEST_CASE("Compare CargoDefault to Alcohol with same name", "[Alcohol][CargoDefault]") {
    auto alcohol = generateCargo(alcoholIndex, defaultGoodsName);
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);

    REQUIRE(!(*cargoDefault == *alcohol));
}