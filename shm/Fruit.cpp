#include "Fruit.hpp"

#include <iostream>
#include <typeinfo>

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDate, Time* time)
    : Fruit(name, amount, basePrice, expiryDate, TIME_TO_SPOIL, time) {}

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDate, size_t timeToSpoil, Time* time)
    : Cargo(name, amount, basePrice, time), _expiryDate(expiryDate), _timeToSpoil(timeToSpoil) {}

size_t Fruit::getPrice() const {
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

bool Fruit::operator==(const Cargo& src) const {
    if (typeid(*this) != typeid(src)) {
        return false;
    }

    auto fruit = static_cast<const Fruit&>(src);
    return fruit.getName() == _name &&
           fruit.getBasePrice() == _basePrice &&
           fruit.getExpiryDate() == _expiryDate &&
           fruit.getTimeToSpoil() == _timeToSpoil;
}

void Fruit::nextDay() {
    if (_timeToSpoil > 0) {
        --_timeToSpoil;
    }
}

std::ostream& Fruit::showCargo(std::ostream& out) const {
    return out << "name: " << _name << ", amount: " << _amount << ", base price: " << _basePrice << ", expiry date: " << _expiryDate << ", time to spoil: " << _timeToSpoil << '\n';
}
