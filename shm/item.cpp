#include "item.hpp"

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity){};

// size_t Item::getPrice() const {
//     return basePrice_ * static_cast<size_t>(rarity_);
// }

Cargo& Item::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Item::operator-=(size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
    } else {
        std::cerr << "Amount of cargo can not be under 0!!!\n";
    }
    return *this;
}

bool Item::operator==(const Cargo& cargo) const {
    return cargo.getName() == getName();
}