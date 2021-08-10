#pragma once

#include "DefaultCargo.hpp"

//Cargo types operator== tests

TEST_CASE("Compare same CargoDefault", "[CargoDefault]") {
    auto cargoDefault = generateCargo(cargoDefaultIndex);
    auto samecargoDefault = generateCargo(cargoDefaultIndex);

    REQUIRE(*samecargoDefault == *cargoDefault);
}

TEST_CASE("Compare CargoDefault to CargoDefault with same name", "[CargoDefault]") {
    auto cargoDefault = generateCargo(cargoDefaultIndex, defaultGoodsName);
    auto secondcargoDefault = generateCargo(secondCargoDefaultIndex, defaultGoodsName);

    REQUIRE(*secondcargoDefault == *cargoDefault);  // Unimportant because CargoDefault is temporary
}

TEST_CASE("Compare different CargoDefault", "[CargoDefault]") {
    auto cargoDefault = generateCargo(cargoDefaultIndex);
    auto secondcargoDefault = generateCargo(secondCargoDefaultIndex);

    REQUIRE(!(*secondcargoDefault == *cargoDefault));
}
