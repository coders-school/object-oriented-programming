#include "Item.hpp"

#include <iostream>
#include <typeinfo>

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), _rarity(rarity) {}

size_t Item::getPrice() const {
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
bool Item::operator==(const Cargo& src) const {
    if (typeid(*this) != typeid(src))
        return false;

    auto item = static_cast<const Item&>(src);
    return item.getName() == _name &&
           item.getAmount() == _amount &&
           item.getBasePrice() == _basePrice &&
           item.getRarity() == _rarity;
}
