#include "cargo.hpp"
#include "ship.hpp"

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

bool Cargo::operator==(Cargo& cargo) {
    return (cargo.getName() == name_ and cargo.getAmount() == amount_);
}
