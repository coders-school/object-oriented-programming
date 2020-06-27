#include "Alcohol.hpp"

#include <iostream>
#include <typeinfo>

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice)
    : Alcohol(name, amount, basePrice, MAX_POWER) {}
Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t power)
    : Cargo(name, amount, basePrice),
      _power(power) {}

size_t Alcohol::getPrice() const {
    return _basePrice * (_power / MAX_POWER);
}

Cargo& Alcohol::operator+=(const size_t amount) {
    if (_amount + amount > _maxAmount) {
        std::cerr << "Not enought space for that cargo!\n";
        return *this;
    }
    _amount += amount;
    return *this;
}

Cargo& Alcohol::operator-=(const size_t amount) {
    if (_amount < amount) {
        std::cerr << "You don't have enough cargo!\n";
        return *this;
    }
    _amount -= amount;
    return *this;
}

bool Alcohol::operator==(const Cargo& src) const {
    if (typeid(*this) != typeid(src))
        return false;

    auto alcohol = static_cast<const Alcohol&>(src);
    return alcohol.getName() == _name &&
           alcohol.getAmount() == _amount &&
           alcohol.getBasePrice() == _basePrice &&
           alcohol.getPower() == _power;
}
