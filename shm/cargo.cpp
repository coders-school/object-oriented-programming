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
    return (this->amount_ == other.amount_ &&
            this->basePrice_ == other.basePrice_ &&
            this->name_ == other.name_);
}
