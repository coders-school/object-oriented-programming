#include "Cargo.hpp"

Cargo& Cargo::operator+=(const size_t amount) {
    _amount += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    _amount -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& src) const {
     return (_name == src._name) && (_amount == src._amount) && (_basePrice == src._basePrice);
}

bool Cargo::operator!=(const Cargo& src) const {
    return !(this == src);
}
