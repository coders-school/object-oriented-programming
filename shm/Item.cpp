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
           item.getBasePrice() == _basePrice &&
           item.getRarity() == _rarity;
}

std::ostream& operator<<(std::ostream& out, const Item::Rarity& rarity) {
    switch (rarity) {
    case Item::Rarity::common:
        out << "common";
        break;
    case Item::Rarity::rare:
        out << "rare";
        break;
    case Item::Rarity::epic:
        out << "epic";
        break;
    case Item::Rarity::legendary:
        out << "legendary";
        break;
    default:
        out << "common";
        break;
    }
    return out;
}

std::ostream& Item::showCargo(std::ostream& out) const {
    return out << "name: " << _name << ", amount: " << _amount << ", base price: " << _basePrice << ", rarity: " << _rarity << '\n';
}
