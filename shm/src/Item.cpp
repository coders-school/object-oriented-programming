#include "shm/inc/Item.hpp"

Item::Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity)
{}

bool Item::operator==(const Cargo& cargo) const {

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

std::string Item::getName() const{
    return name_;
}

size_t Item::getAmount() const {
    return amount_;
}

size_t Item::getBasePrice() const {
    return basePrice_;
}

size_t Item::getPrice() const {
    return basePrice_ * static_cast<size_t>(rairty_);
}
Item::Rarity Item::getRarity() const {
    return rairty_;
}
