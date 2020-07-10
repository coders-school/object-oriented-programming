#include "Cargo.hpp"

std::string Cargo::getName() const { return name_; }
size_t Cargo::getAmount() const { return amount_; }
size_t Cargo::getBasePrice() const { return basePrice_; }

Cargo& Cargo::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    if (amount_ > amount) {
        amount_ -= amount;
    }
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) {
    return name_ == cargo.name_;
}
