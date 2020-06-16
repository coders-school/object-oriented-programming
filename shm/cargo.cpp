#include "cargo.hpp"

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& other) {
    return (this->amount_ == other.amount_ &&
            this->basePrice_ == other.basePrice_ &&
            this->name_ == other.name_);
}
