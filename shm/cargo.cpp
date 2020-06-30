#include "cargo.hpp"

#include <iostream>

Cargo::Cargo(std::string name, size_t amount, size_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice) {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount > amount_) {
        std::cerr << "Not enough amount of this cargo!\n";
        return *this;
    }
    amount_ -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& rhs) const {
    return (typeid(*this).name() == typeid(rhs).name() &&
            equals(rhs));
}
