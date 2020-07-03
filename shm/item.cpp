#include "item.hpp"

#include <iostream>

Item::Item(uint32_t amount, const std::string& name, uint32_t basePrice, Rarity rarity)
    : Cargo(amount, name, basePrice), rarity_(rarity) {}

Item::~Item() {}

std::string Item::getName() const {
    return "Item " + name_;
}

uint32_t Item::getAmount() const {
    return amount_;
}

uint32_t Item::getBasePrice() const {
    return basePrice_;
}

double Item::getPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}

Item::Rarity Item::getRarity() const {
    return rarity_;
}

Cargo& Item::operator+=(uint32_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Item::operator-=(uint32_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
        return *this;
    }
    std::cout << "There is no so many items!\n";
    return *this;
}

bool Item::operator==(const Cargo& cargo) const {
    auto item = dynamic_cast<const Item&>(cargo);
    if (typeid(*this) != typeid(cargo)) {
        return false;
    }
    return (item.getBasePrice() == basePrice_) && (item.getName() == name_) && (item.getRarity() == rarity_);
}

std::shared_ptr<Cargo> Item::clone() const {
    return std::make_shared<Item>(*this);
}
