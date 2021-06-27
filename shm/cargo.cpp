#include "cargo.hpp"

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Cargo::operator == (const Cargo& cargo) const {
    return cargo.getName() == name_ && cargo.getBasePrice() == basePrice_; // I think basePrice  is usless in this example.
} 

std::string Cargo::getName() const {
    return name_;
}
size_t Cargo::getAmount() const {
    return amount_;
}
size_t Cargo::getBasePrice() const {
    return basePrice_;
}
