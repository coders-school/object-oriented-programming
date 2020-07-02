#include "Cargo.hpp"

Cargo& Cargo::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
        return *this;
    }
    amount_ -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const {
    return (name_ == cargo.name_);
}

bool Cargo::operator!=(const Cargo& cargo) const {
    return (name_ != cargo.name_);
}

