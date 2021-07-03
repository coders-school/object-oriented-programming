#include "shm/inc/Cargo.hpp"
#include "shm/inc/Player.hpp"

#include <iostream>

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice) 
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
{}

Cargo& Cargo::operator+=(const size_t amount) {
    size_t availableSpace = Player::getAvailableSpace();
    if (amount_ + amount > availableSpace) {
        std::cerr << "You don't have enough space on the ship\0";
        return *this;
    }
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    if (cargo_ < cargo) {
        std::cerr << "You don't have that much cargo on the ship\0";
        return *this;
    }
    cargo_ -= cargo;
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const {
    return cargo.name_ == name_ && cargo.basePrice_ == basePrice_;
}
