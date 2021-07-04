#include <stdexcept>

#include "Cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_{name}, amount_{amount}, basePrice_{basePrice} {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount_ < amount) {
        throw std::invalid_argument("Not allowed! You will be below zero!");
    }
    amount_ -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& other) const {
    return name_ == other.name_ and basePrice_ == other.basePrice_;
}

const std::string& Cargo::getName() const {
    return name_;
}

size_t Cargo::getAmount() const {
    return amount_;
}

size_t Cargo::getBasePrice() const {
    return basePrice_;
}
