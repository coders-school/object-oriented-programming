#include "Item.hpp"

Item::Item(const std::string& name, const size_t amount, const size_t basePrice, const Rarity rarity):
    Cargo(name, amount, basePrice),
    rarity_(rarity)
{}

size_t Item::getPrice() const {
    switch (rarity_) {
    case Rarity::Common:
        return getBasePrice() / 3;

    case Rarity::Rare:
        return getBasePrice() / 2;

    case Rarity::Epic:
        return getBasePrice();

    case Rarity::Legendary:
        return getBasePrice() * 4;
    }
    return 0;
}

std::string Item::getName() const { 
    return "Item: " + name_; 
}

size_t Item::getAmount() const { 
    return amount_; 
}

size_t Item::getBasePrice() const { 
    return basePrice_; 
}
