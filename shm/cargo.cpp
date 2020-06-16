#include "cargo.hpp"

Cargo::Cargo(const std::string& name, size_t basePrice, size_t amount)
    : name_(name), basePrice_(basePrice), amount_(amount) {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& other) {
    return (amount_ == other.amount_ &&
            basePrice_ == other.basePrice_ &&
            name_ == other.name_);
}
