#include "Cargo.hpp"

#include <iostream>
Cargo::Cargo(const std::string& name,
             size_t amount,
             size_t basePrice)
    : _name(name), _amount(amount), _basePrice(basePrice) {}

Cargo& Cargo::operator+=(const size_t amount) {
    if (_amount + amount > _maxAmount) {
        std::cerr << "Not enought space for that cargo!\n";
        return *this;
    }

    _amount += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    if (_amount < amount) {
        std::cerr << "You dont have enough cargo!\n";
        return *this;
    }

    _amount -= amount;
    return *this;
}

bool Cargo::operator==(const Cargo& src) const {
    return (_name == src._name) && (_amount == src._amount) && (_basePrice == src._basePrice);
}

bool Cargo::operator!=(const Cargo& src) const {
    return !(*this == src);
}
