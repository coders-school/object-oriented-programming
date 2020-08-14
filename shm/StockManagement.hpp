#pragma once

#include "Cargo.hpp"

class StockManagement {
private:
    CargoPtr findCargo(const CargoPtr& cargo);

protected:
    CargoStock stock_;

public:
    void removeCargoFromStock(const CargoPtr& cargo, size_t amount);
    void addCargoToStock(const CargoPtr& cargo, size_t amount);
    CargoPtr getCargo(size_t index);
};
