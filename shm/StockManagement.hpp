#pragma once

#include "Cargo.hpp"

class StockManagement {
private:
    static CargoPtr findCargo(const CargoStock& stock_, const CargoPtr& cargo);

public:
    static void removeCargoFromStock(CargoStock& stock_, const CargoPtr& cargo, size_t amount);
    static void addCargoToStock(CargoStock& stock_, const CargoPtr& cargo, size_t amount);
    static CargoPtr getCargo(const CargoStock& stock, size_t index);
};
