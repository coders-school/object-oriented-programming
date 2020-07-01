#include "fruit.hpp"

#include <string>

//Override from Cargo
Fruit::Fruit(std::string name, size_t amount, size_t basePrice, size_t expiryDate, size_t timeElapsed)
    : Cargo(name, amount, basePrice),
      expiryDate_(expiryDate),
      timeElapsed_(timeElapsed) {}

size_t Fruit::getPrice() const {
    if (timeToSpoil_) {
        return static_cast<size_t>(basePrice_ * static_cast<float>(timeToSpoil_) / expiryDate_);
    }
    return 0;
}
std::string Fruit::getName() const {
    return name_;
}
size_t Fruit::getAmount() const {
    return amount_;
}
size_t Fruit::getBasePrice() const {
    return basePrice_;
}

Fruit& Fruit::operator--() {
    if (amount_) {
        --amount_;
    }
    return *this;
}

size_t Fruit::getExpiryDate() const {
    return expiryDate_;
}

size_t Fruit::getTimeElapsed() const {
    return timeElapsed_;
}
