#include "Item.h"

Item::Item(std::string& name, size_t amount, size_t base_price, Rarity rarity)
    : Cargo(name, amount, base_price), rarity_(rarity){};

//override from Cargo
size_t Item::getPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}