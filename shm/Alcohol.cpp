#include "Alcohol.hpp"

#include <iostream>
#include <typeinfo>

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, Time* time)
    : Alcohol(name, amount, basePrice, MAX_POWER, time) {
}

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t power, Time* time)
    : Cargo(name, amount, basePrice, time),
      _power(power) {
}

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
           alcohol.getBasePrice() == _basePrice &&
           alcohol.getPower() == _power;
}

void Alcohol::nextDay() {
  _basePrice = (size_t)(_basePrice * 1.2);
    //if (_power > 0) {
    //  _power *= 0.95;
    //}
}

std::ostream& Alcohol::showCargo(std::ostream& out) const {
    return out << "name: " << _name << ", amount: " << _amount << ", base price: " << _basePrice << ", power: " << _power << '\n';
}
