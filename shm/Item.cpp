#include "Item.hpp"

size_t Item::getPrice() const override {
    return _basePrice * static_cast<int>(_rarity);
}
Cargo& Item::operator+=(const size_t amount) {
    if (_amount + amount > _maxAmount) {
        std::cerr << "Not enought space for that cargo!\n";
        return *this;
    }
    _amount += amount;
    return *this;
}

Cargo& Item::operator-=(const size_t amount) {
    if (_amount < amount) {
        std::cerr << "You don't have enough cargo!\n";
        return *this;
    }
    _amount -= amount;
    return *this;
}
