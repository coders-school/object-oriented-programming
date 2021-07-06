#include "shm/inc/Cargo.hpp"
#include "shm/inc/Player.hpp"

#include <stdexcept>

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice) 
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
{}

Cargo& Cargo::operator+=(const size_t amount) {
    if (amount_ + amount > MAX_AMOUNT_OF_CARGO) {
        throw std::out_of_range("You don't have enough room on the ship!");
    }
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    if (amount_ < amount) {
        throw std::out_of_range("You don't have that much cargo on the ship!");
    }
    amount_ -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const {
    return cargo.name_ == name_ &&
           cargo.basePrice_ == basePrice_;
}
