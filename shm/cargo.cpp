#include <iostream>
#include "cargo.hpp"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice, Time *time)
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
    , time_(time)
    {
        time->attachObeserver(this);
    }

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
    } else {
        std::cerr << "Amount of cargo can not be under 0!!!\n";
    }
    return *this;
}

bool Cargo::operator== (const Cargo& cargo) const {
    return cargo.getName() == name_;
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
