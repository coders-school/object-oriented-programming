#include "cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice) {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount_ > 0) {
        amount_ -= amount;
    }
    return *this;
}

bool Cargo::operator==(const Cargo& cargoToCheck) const {
    return name_ == cargoToCheck.name_ &&
           amount_ == cargoToCheck.amount_ &&
           basePrice_ == cargoToCheck.basePrice_;
}
