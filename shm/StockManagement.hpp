#pragma once

#include "Cargo.hpp"

class StockManagement {
protected:
    CargoStock stock_{};

public:
    virtual CargoPtr findCargo(const CargoPtr& cargo) const = 0;
    virtual void removeCargoFromStock(const CargoPtr& cargo, size_t amount) = 0;
    virtual void addCargoToStock(const CargoPtr& cargo, size_t amount) = 0;
};


