#include "Fruit.hpp"

Fruit::Fruit(uint16_t amount, const std::string& name, uint16_t basePrice, uint16_t expiryDate)
    : Cargo(amount, name, basePrice), expiryDate_(expiryDate) {}

Fruit::Fruit(uint16_t amount, const std::string& name, uint16_t basePrice, uint16_t expiryDate, uint16_t timeElapsed)
    : Cargo(amount, name, basePrice), expiryDate_(expiryDate), timeElapsed_(timeElapsed) {}

std::string Fruit::getName() const {
    return name_;
}

uint16_t Fruit::getAmount() const {
    return amount_;
}

uint16_t Fruit::getBasePrice() const {
    return basePrice_;
}

uint16_t Fruit::getExpiryDate() const {
    return expiryDate_;
}

uint16_t Fruit::getTimeElapsed() const {
    return timeElapsed_;
}

uint16_t Fruit::getPrice() const {
    return static_cast<int>(basePrice_ * float(timeElapsed_ / expiryDate_));
}

Cargo& Fruit::operator+=(const uint16_t newFruitAmount) {
    amount_ += newFruitAmount;
    return *this;
}

Cargo& Fruit::operator-=(const uint16_t usedFruitAmount) {
    if (amount_ - usedFruitAmount > amount_) {
        return *this;
    }
    amount_ -= usedFruitAmount;
    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
    if (typeid(*this) == typeid(cargo)) {
        return cargo.getName() == name_ && cargo.getAmount() == amount_ &&
               cargo.getBasePrice() == basePrice_ && cargo.getPrice() == getPrice();
    }
    return false;
}

Fruit& Fruit::operator--() {
    --timeElapsed_;
    return *this;
}

void Fruit::nextDay() {
    operator--();
}