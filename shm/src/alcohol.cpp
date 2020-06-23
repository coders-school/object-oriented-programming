#include "alcohol.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {}

Alcohol::Alcohol(const std::string& name, size_t amount, double basePrice, double volume)
    : Cargo(name, amount, basePrice), volume_(volume) {}

double Alcohol::getPrice() const {
    return volume_ == 0.96 ? getBasePrice()
                           : getBasePrice() * (0.96 - getVolume());
}

Cargo& Alcohol::operator+=(const size_t& amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(const size_t& amount) {
    if (amount_ >= amount) {
        amount_ -= amount;
    }
    return *this;
}

bool Alcohol::operator==(Cargo& alcohol) const {
    return getName() == alcohol.getName() &&
           getBasePrice() == alcohol.getBasePrice() &&
           getPrice() == alcohol.getPrice();
}