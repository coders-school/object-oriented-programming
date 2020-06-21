#include "cargo.hpp"

Cargo::Cargo(uint32_t amount, std::string name, uint32_t basePrice)
    : amount_(amount), name_(name), basePrice_(basePrice) {}
Cargo::~Cargo() {}

std::string Cargo::getName() const {
    return name_;
}
uint32_t Cargo::getAmount() const {
    return amount_;
}
uint32_t Cargo::getBasePrice() const {
    return basePrice_;
}

Cargo& Cargo::operator+=(uint32_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(uint32_t amount) {
    amount_ -= amount;
    return *this;

    bool Cargo::operator==(Cargo& cargo) {
        return (name_ == cargo.name_) && (amount_ == cargo.amount_) && (base_price_ == cargo.base_price_);
    }
