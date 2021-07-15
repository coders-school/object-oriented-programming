#include <algorithm>
#include <stdexcept>
#include <vector>

#include "Cargo.hpp"
#include "Warehouse.hpp"

Warehouse::Warehouse(CargoVec cargoVec)
    : cargoVec_(std::move(cargoVec)) {}

const Warehouse::CargoVec& Warehouse::getCargoVec() const {
    return cargoVec_;
}

void Warehouse::load(std::unique_ptr<Cargo> cargo) {
    if (!cargo) {
        return;
    }

    Cargo* storedCargo = nullptr;
    for (const auto& el : cargoVec_) {
        if (*cargo == *el) {
            storedCargo = el.get();
            break;
        }
    }

    if (!storedCargo) {
        for (auto& el : cargoVec_) {
            if (!el) {
                el = std::move(cargo);  //move cargo into empty cargo space
                return;
            }
        }
        cargoVec_.push_back(std::move(cargo));  //move cargo into vector
        return;
    }
    *storedCargo += cargo->getAmount();  //transfer amount into comperable cargo
    //here cargo will be destroyed
}

void Warehouse::unload(const Cargo* const cargo) {  //ver A
    if (!cargo) {
        return;
    }
    for (auto& el : cargoVec_) {
        if (el.get() == cargo) {  //equal pointers -> equal amount
            el.reset();
            //we leave empty cargo space in store here
            cargoVec_.erase(std::remove(begin(cargoVec_), end(cargoVec_), nullptr), end(cargoVec_));
            return;
        }
    }
    throw std::logic_error("Store: Not my Cargo!");
}
