#include "item.hpp"

#include <iostream>

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {}

size_t Item::getPrice() const {
    return basePrice_ * priceMultipliers_.at(rarity_);
}

void Item::nextDay(){
    return;
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
