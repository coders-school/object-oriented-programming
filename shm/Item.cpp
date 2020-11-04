#include "Item.hpp"

Item::Item(uint16_t amount, const std::string& name, uint16_t basePrice, Rarity rarity)
    : Cargo(amount, name, basePrice), rarity_(rarity) {}

std::string Item::getName() const {
    return name_;
}

uint16_t Item::getAmount() const {
    return amount_;
}

uint16_t Item::getBasePrice() const {
    return basePrice_;
}

Rarity Item::getRarity() const {
    return rarity_;
}

uint16_t Item::getPrice() const {
    return basePrice_ * static_cast<int>(getRarity());
}

Cargo& Item::operator+=(const uint16_t newItemAmount) {
    amount_ += newItemAmount;
    return *this;
}

Cargo& Item::operator-=(const uint16_t usedItemAmount) {
    if (amount_ - usedItemAmount > amount_) {
        return *this;
    }
    amount_ -= usedItemAmount;
    return *this;
}

bool Item::operator==(const Cargo& cargo) const {
    if (typeid(*this) == typeid(cargo)) {
        return cargo.getName() == name_ && cargo.getAmount() == amount_ &&
               cargo.getBasePrice() == basePrice_ && cargo.getPrice() == getPrice();
    }
    return false;
}

void Item::nextDay() {
    return;
}