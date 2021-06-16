#include "../inc/Cargo.hpp"
#include <iostream>

Cargo& Cargo::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
    } else {
        std::cerr << "Amount of cargo can't be under 0\n";
    }
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const {
    return cargo.name_ == name_;
}
