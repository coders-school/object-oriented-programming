#include "cargo.hpp"

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& cargoToCheck) const {
    return name_ == cargoToCheck.name_ &&
           amount_ == cargoToCheck.amount_ &&
           basePrice_ == cargoToCheck.basePrice_;
}
