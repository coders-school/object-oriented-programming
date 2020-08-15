#pragma once

#include "Cargo.hpp"

class StockManagement {
protected:
    CargoStock stock_;

    CargoPtr findCargo(const CargoPtr& cargo);

public:
    void removeCargoFromStock(const CargoPtr& cargo, size_t amount);
    void addCargoToStock(const CargoPtr& cargo, size_t amount);
    CargoPtr getCargo(size_t index);
};
