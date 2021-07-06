#include "shm/inc/Item.hpp"

#include <stdexcept>

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
    if (amount_ + amount > MAX_AMOUNT_OF_CARGO) {
        throw std::out_of_range("Maximum amount of items reached!");
    }
    amount_ += amount;
    return *this;
}

Cargo& Item::operator-=(size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
    }
    return *this;
}

void Item::nextDay() {
    daysToDestruction_--;
    if (daysToDestruction_ == 0) {
        std::cout << "The item has been destroyed\n";
    }
}

size_t Item::getPrice() const {
    return basePrice_ * static_cast<size_t>(rarity_);
}
Item::Rarity Item::getRarity() const {
    return rarity_;
}
