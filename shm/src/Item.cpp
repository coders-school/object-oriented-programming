#include "shm/inc/Item.hpp"

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity)
{}

bool Item::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Item)) {
        const Item* item = static_cast<const Item*>(&cargo);
        return name_ == item->getName() && basePrice_ == item->getBasePrice() &&
               rarity_ == item->getRarity();
    }

    return false;
}

Cargo& Item::operator+=(size_t amount) {
    amount_ += amount;

    return *this;
}

Cargo& Item::operator-=(size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
    }

    return *this;
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

size_t Item::getPrice() const {
    return basePrice_ * static_cast<size_t>(rarity_);
}
Item::Rarity Item::getRarity() const {
    return rarity_;
}
