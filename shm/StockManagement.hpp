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
    bool isEmpty() const { return stock_.size() == 0; };
};
