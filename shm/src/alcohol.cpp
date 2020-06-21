#include "alcohol.hpp"

Alcohol::Alcohol(std::string name, size_t amount, double basePrice,  double volume)
    : Cargo(name, amount, basePrice), volume_(volume) {
    price_ = setPrice();
}

double Alcohol::setPrice() const {
    return volume_ == 0.96 ? getBasePrice()
                           : getBasePrice() * (0.96 - getVolume());
}
