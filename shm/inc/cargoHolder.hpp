#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#include "cargo.hpp"

class CargoHolder {
public:
    virtual const std::vector<std::shared_ptr<Cargo>>& getAllCargo() const = 0;
    virtual void receiveCargo(Cargo* cargo, size_t amount, CargoHolder* cargoHolder) = 0;
    virtual void clearEmptyCargos() = 0;

    virtual void printAllCargoOwned() const {
        auto& cargo = getAllCargo();
        std::for_each(cargo.begin(), cargo.end(), [counter{1}](const std::shared_ptr<Cargo> item) mutable {
            std::cout << counter++ << ") " << item->oneLineDescription() << '\n';
        });
    }
};
