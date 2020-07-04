#include "Item.h"

Item::Item(std::string& name, size_t amount, size_t base_price, Rarity rarity)
    : Cargo(name, amount, base_price), rarity_(rarity){};

//override from Cargo
size_t Item::getPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}

//override from Cargo
void Item::nextDay() {
}

//override from Cargo
bool Item::operator==(Cargo& cargo) const {
    Item* otherItem = dynamic_cast<Item*>(std::addressof(cargo));

    if (!otherItem) {
        return false;
    }

    return name_ == otherItem->name_ && amount_ == otherItem->amount_ && basePrice_ == otherItem->basePrice_ && rarity_ == otherItem->rarity_;
}