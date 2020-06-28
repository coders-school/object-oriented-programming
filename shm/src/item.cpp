#include "item.hpp"

#include <typeinfo>

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity) {}

Cargo& Item::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Item::operator-=(size_t amount) {
    (amount_ <= amount) ? amount_ = 0 : amount_ -= amount;
    return *this;
}

bool Item::operator==(const Cargo& other) const {
    if (typeid(*this).hash_code() != typeid(other).hash_code()) {
        return false;
    }
    return (amount_ == other.getAmount() && basePrice_ == other.getBasePrice() &&
            name_ == other.getName() && getPrice() == other.getPrice());
}
