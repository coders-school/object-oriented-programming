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
bool Cargo::operator==(const Cargo& cargo) const {
    return (name_ == cargo.name_);
}

std::string Cargo::getName() const {
    return name_;
}
