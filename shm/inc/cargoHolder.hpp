#pragma once

#include "cargo.hpp"

class CargoHolder {
public:
    virtual void receiveCargo(Cargo* cargo, size_t amount, CargoHolder* cargoHolder) = 0;
    virtual void clearEmptyCargos() = 0;
};
