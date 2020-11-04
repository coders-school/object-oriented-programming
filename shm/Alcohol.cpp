#include "Alcohol.hpp"

Alcohol::Alcohol(uint16_t amount, const std::string& name, uint16_t basePrice, uint16_t percentage)
    : Cargo(amount, name, basePrice), percentage_(percentage) {}

std::string Alcohol::getName() const {
    return name_;
}

uint16_t Alcohol::getAmount() const {
    return amount_;
}

uint16_t Alcohol::getBasePrice() const {
    return basePrice_;
}

uint16_t Alcohol::getPercentage() const {
    return percentage_;
}

uint16_t Alcohol::getPrice() const {
    return static_cast<int>(basePrice_ * getPercentage() / MAX_POWER);
}

Cargo& Alcohol::operator+=(const uint16_t newAlcoholAmount) {
    amount_ += newAlcoholAmount;
    return *this;
}

Cargo& Alcohol::operator-=(const uint16_t usedAlcoholAmount) {
    if (amount_ - usedAlcoholAmount > amount_) {
        return *this;
    }
    amount_ -= usedAlcoholAmount;
    return *this;
}

bool Alcohol::operator==(const Cargo& cargo) const {
    if (typeid(*this) == typeid(cargo)) {
        return cargo.getName() == name_ && cargo.getAmount() == amount_ &&
               cargo.getBasePrice() == basePrice_ && cargo.getPrice() == getPrice();
    }
    return false;
}

void Alcohol::nextDay() {
    return;
}