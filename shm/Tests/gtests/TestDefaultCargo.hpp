#pragma once

#include "DefaultCargo.hpp"

//Cargo types operator== tests

TEST(CargoDefault, Compare_same_CargoDefault) {
    auto cargoDefault = generateCargo(cargoDefaultIndex);
    auto samecargoDefault = generateCargo(cargoDefaultIndex);

    EXPECT_TRUE(*samecargoDefault == *cargoDefault);
}

TEST(CargoDefault, Compare_CargoDefault_to_CargoDefault_with_same_name) {
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);
    auto secondcargoDefault = generateCargo(secondCargoDefaultIndex, defaultGoodsName);

    EXPECT_TRUE(*secondcargoDefault == *cargoDefault);  // Unimportant because CargoDefault is temporary
}

TEST(CargoDefault, Compare_different_CargoDefault) {
    auto cargoDefault = generateCargo(cargoDefaultIndex);
    auto secondcargoDefault = generateCargo(secondCargoDefaultIndex);

    EXPECT_TRUE(!(*secondcargoDefault == *cargoDefault));
}
