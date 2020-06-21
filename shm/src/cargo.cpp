#include "cargo.hpp"

#include <iostream>

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice) {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
    } else if (amount_ > 0) {
        amount_ -= amount;
    } else {
        std::cerr << "Amount equal zero\n";
    }
    return *this;
}

bool Cargo::operator==(const Cargo& cargoToCheck) const {
    return name_ == cargoToCheck.name_ &&
           amount_ == cargoToCheck.amount_ &&
           basePrice_ == cargoToCheck.basePrice_;
}
