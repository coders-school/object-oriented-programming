#include "Cargo.hpp"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice)
    : name_{name}, amount_{amount}, basePrice_{basePrice} {}


Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& other) const {
    return (name_ == other.name_ and amount_ == other.amount_ and basePrice_ == other.basePrice_);
} //???

