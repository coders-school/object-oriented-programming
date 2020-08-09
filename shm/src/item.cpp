#include "item.hpp"

Item::Item(const std::string& name, uint16_t amount, uint16_t basePrice, Rarity rarity)
    : Cargo(name, amount, basePrice), rarity_(rarity)
{}
uint16_t Item::GetPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}

std::string Item::GetName() const {
    return name_;
}

bool Item::operator==(const Cargo& cargoToCheck) const {
    if (typeid(cargoToCheck) != typeid(Item&)) 
        return false;

    auto item = static_cast<const Item*>(&cargoToCheck);
    return name_ == item->GetName() &&
           amount_ == item->getAmount() &&
           basePrice_ == item->getBasePrice() &&
           rarity_ == item->getRarity();
}

Cargo& Item::operator+=(uint16_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Item::operator-=(uint16_t amount) {
    if (amount >= amount_) 
        amount_ = 0;
    else
        amount_ -= amount;
    
    return *this;
}
