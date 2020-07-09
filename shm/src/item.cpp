#include "item.hpp"

#include <iostream>

#include "globaltime.hpp"

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {
    GlobalTime::getGlobalTime()->addObserver(this);
}

size_t Item::getPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}

void Item::nextDay() {
    return;
}

Item::~Item() {
    GlobalTime::getGlobalTime()->removeObserver(this);
}

bool Item::operator==(const Cargo& cargoToCheck) const {
    if (typeid(cargoToCheck) != typeid(Item&)) {
        return false;
    }

    auto itemToCheck = static_cast<const Item*>(&cargoToCheck);
    return name_ == itemToCheck->getName() &&
           amount_ == itemToCheck->getAmount() &&
           basePrice_ == itemToCheck->getBasePrice() &&
           rarity_ == itemToCheck->getRarity();
}

Cargo& Item::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Item::operator-=(size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
    } else if (amount_ > 0) {
        amount_ -= amount;
    } else {
        std::cerr << "Amount equal zero\n";
    }
    return *this;
}
