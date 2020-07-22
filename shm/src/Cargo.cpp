#include "Cargo.hpp"

Cargo::Cargo(const std::string& name, uint16_t amount, uint16_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice) {}

Cargo& Cargo::operator+=(const uint16_t amount) {
    amount_ += amount;
    return *this;
}
Cargo& Cargo::operator-=(const uint16_t amount) {
    if (amount_ - amount > amount_) {
        amount_ -= amount;
    }
    return *this;
}
bool Cargo::operator==(const Cargo& cargo) const {
    return cargo.getName() == name_ && cargo.getBasePrice() == basePrice_;
}

std::string Cargo::getName() const {
    return name_;
}
uint16_t Cargo::getAmount() const {
    return amount_;
}
uint16_t Cargo::getBasePrice() const {
    return basePrice_;
}
