#include "Item.h"

Item::Item(std::string name, size_t amount, size_t base_price, Time* time, Rarity rarity)
    : Cargo(name, amount, base_price, time), rarity_(rarity){};

//override from Cargo
std::string Item::getName() const {
    return name_;
}

//override from Cargo
size_t Item::getAmount() const {
    return amount_;
}

//override from Cargo
size_t Item::getBasePrice() const {
    return basePrice_;
}

//override from Cargo
size_t Item::getPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}

//override from Cargo
void Item::nextDay() {
    // it is suppossed to be empty, no mistake here
}

//override from Cargo
bool Item::operator==(Cargo& cargo) const {
    Item* otherItem = dynamic_cast<Item*>(std::addressof(cargo));

    if (!otherItem) {
        return false;
    }

    return name_ == otherItem->name_ && amount_ == otherItem->amount_ && basePrice_ == otherItem->basePrice_ && rarity_ == otherItem->rarity_;
}

//override from Cargo
std::string Item::getDescription() const {
    return "Name: " + this->name_ + " Rarity: " + rarityMap[this->rarity_] + " Amount: " + std::to_string(this->amount_) + " Price: " + std::to_string(this->getPrice());
}