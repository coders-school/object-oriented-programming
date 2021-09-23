#include "cargo.hpp"
#include <iostream>


Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice, std::shared_ptr<Time> time)
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
    , time_(time)
    {
        if (time_) {
            time_->attachObserver(this);
        }
    }

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
    } else {
        
    }
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const {
    return cargo.getName() == getName();
}
