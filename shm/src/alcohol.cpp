#include "alcohol.hpp"

#include <iostream>

#include "globaltime.hpp"

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice)
    : Alcohol(name, amount, basePrice, kBasePower) {
    GlobalTime::getGlobalTime()->addObserver(this);
}

Alcohol::Alcohol(const std::string& name, size_t amount, size_t basePrice, float power)
    : Cargo(name, amount, basePrice), power_(power) {}

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(static_cast<float>(basePrice_) * (power_ / kBasePower));
}

std::string Alcohol::oneLineDescription() const {
    return Cargo::oneLineDescription() + "\tPower: " + std::to_string(getPower());
}

void Alcohol::nextDay() {
    return;
}

Alcohol::~Alcohol() {
    GlobalTime::getGlobalTime()->removeObserver(this);
}

bool Alcohol::operator==(const Cargo& cargoToCheck) const {
    if (typeid(cargoToCheck) != typeid(Alcohol&)) {
        return false;
    }

    auto alcoToCheck = static_cast<const Alcohol*>(&cargoToCheck);
    return name_ == alcoToCheck->getName() &&
           amount_ == alcoToCheck->getAmount() &&
           basePrice_ == alcoToCheck->getBasePrice() &&
           power_ == alcoToCheck->getPower();
}

Cargo& Alcohol::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
    } else if (amount_ > 0) {
        amount_ -= amount;
    } else {
        std::cerr << "Amount equal zero\n";
    }
    return *this;
}
