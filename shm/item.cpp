#include "item.hpp"

#include <string>

#include "cargo.hpp"

Item::Item(std::string name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice),
      rarity_(rarity) {}

//Override from Cargo
size_t Item::getPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}
std::string Item::getName() const {
    return name_;
}
size_t Item::getAmount() const {
    return amount_;
}
size_t Item::getBasePrice() const {
    return basePrice_;
}

Item::Rarity Item::getRarity() const {
    return rarity_;
}
