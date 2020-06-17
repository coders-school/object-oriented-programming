#include "cargo.hpp"

Cargo& Cargo::operator+=(uint8_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(uint8_t amount) {
    amount_ -= amount;
    return *this;
}
