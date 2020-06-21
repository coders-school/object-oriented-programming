#include "fruit.hpp"

Fruit::Fruit(const std::string& name, size_t amount, size_t basePrice, size_t timeToSpoil)
    : Cargo(name, amount, basePrice), timeToSpoil_(timeToSpoil) {}

size_t Fruit::getPrice() const {
    return static_cast<size_t>(basePrice_ * (float(timeToSpoil_) / expiryDate_));
}

Fruit& Fruit::operator--() {
    --timeToSpoil_;
    return *this;
}
