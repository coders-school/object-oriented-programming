#include "Cargo.hpp"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice)
{}

Cargo& Cargo::operator+=(const size_t& amount) {
    amount_ += amount;
    return *this;
}
Cargo& Cargo::operator-=(const size_t& amount) {
    amount_ -= amount;
    return *this;
}

std::string const Cargo::getName() {
    return name_;
}
