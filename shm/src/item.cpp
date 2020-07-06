#include "item.hpp"

size_t Item::getPrice() const {
    return basePrice_ * static_cast<size_t>(rairty_);
}

std::string Item::getName() const { return name_; }
size_t Item::getAmount() const { return amount_; }
size_t Item::getBasePrice() const { return basePrice_; }
Item::Rarity Item::getRarity() const { return rairty_; }

bool Item::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Item)) {
        const Item* item = static_cast<const Item*>(&cargo);
        return name_ == item->getName() &&
               amount_ == item->getAmount() &&
               basePrice_ == item->getBasePrice() &&
               rairty_ == item->getRarity();
    }
    return false;
}
bool Item::operator!=(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Item)) {
        const Item* item = static_cast<const Item*>(&cargo);
        return !(this == item);
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
        return *this;
    }
    return *this;
}

Cargo* Item::clone() {
    std::shared_ptr<Item> sp_Item = std::make_shared<Item>(*this);
    return sp_Item.get();
}
