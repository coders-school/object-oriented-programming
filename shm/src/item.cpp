#include "item.hpp"

Item::Item(std::string name, size_t amount, double basePrice)
    : Cargo(name, amount, basePrice) {
    rarity_ = Rarity::common;
    price_ = setPrice();
}

Item::Item(std::string name, size_t amount, double basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {
    price_ = setPrice();
}

double Item::setPrice() const {
    return getBasePrice() * static_cast<int>(rarity_);
}
