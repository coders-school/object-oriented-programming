#include "Cargo.hpp"

Cargo::Cargo(const std::string& name, const size_t amount, const size_t basePrice):
    name_(name),
    amount_(amount),
    basePrice_(basePrice)
{}

bool Cargo::operator==(const Cargo& cargo) const {
    return (name_ == cargo.getName() &&
        amount_ == cargo.getAmount() &&
        basePrice_ == cargo.getBasePrice());
}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    amount_ = (amount_ > amount)? amount_ - amount : 0;
    return *this;
}

std::string Cargo::getName() const { return name_; }

size_t Cargo::getAmount() const { return amount_; }

size_t Cargo::getBasePrice() const { return basePrice_; }
