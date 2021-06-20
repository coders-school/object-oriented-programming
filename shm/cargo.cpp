#include "cargo.hpp"

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

std::string Cargo::getName() {
    return name_;
}
size_t Cargo::getAmount() {
    return amount_;
}
size_t Cargo::getBasePrice() {
    return basePrice_;
}