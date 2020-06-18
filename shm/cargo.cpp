#include "cargo.hpp"

Cargo& Cargo::operator+=(uint32_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(uint32_t amount) {
    amount_ -= amount;
    return *this;
}
