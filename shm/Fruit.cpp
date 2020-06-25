#include "Fruit.hpp"

size_t Fruit::getPrice() const override {
    return _basePrice * (_timeToSpoil / _expiryDate);
}

Fruit& Fruit::operator--() {
    if (_timeToSpoil > 0) {
        --_timeToSpoil;
    }
    return *this;
}
Cargo& Fruit::operator+=(const size_t amount) {
    if (_amount + amount > _maxAmount) {
        std::cerr << "Not enought space for that cargo!\n";
        return *this;
    }
    _amount += amount;
    return *this;
}

Cargo& Fruit::operator-=(const size_t amount) {
    if (_amount < amount) {
        std::cerr << "You don't have enough cargo!\n";
        return *this;
    }
    _amount -= amount;
    return *this;
}
