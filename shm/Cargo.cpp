#include "Cargo.hpp"

Cargo& Cargo::operator+=(const size_t amount) {
    _amount += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    _amount -= amount;
    return *this;
}
