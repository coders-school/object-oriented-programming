#include "Item.hpp"

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {
}

Cargo& Item::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Item::operator-=(const size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
        return *this;
    }
    amount_ -= amount;
    return *this;
}

bool Item::operator==(const Cargo& cargo) const {
    return getName() == cargo.getName() &&
           getBasePrice() == cargo.getBasePrice() &&
           getPrice() == cargo.getPrice();
}

bool Item::operator!=(const Cargo& cargo) const {
    return getName() != cargo.getName() ||
           getBasePrice() != cargo.getBasePrice() ||
           getPrice() != cargo.getPrice();
}
