#include "cargo.hpp"

Cargo::Cargo()
    : Cargo("", 0, 0) {}

Cargo::Cargo(std::string name, size_t amount, size_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice) {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount_ >= amount) {
        amount_ -= amount;
    }
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const {
    return (name_ == cargo.getName() &&
            basePrice_ == cargo.getBasePrice() &&
            amount_ == cargo.getAmount());
}
