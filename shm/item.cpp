#include "item.hpp"

size_t Item::getPrice() const
{
    return basePrice_ * static_cast<int>(rarity_);
}

Cargo &Item::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}

Cargo &Item::operator-=(size_t amount)
{

    if (amount_ < amount)
    {
        amount_ = 0;
    }
    else
    {
        amount_ -= amount;
    }
    return *this;
}

bool Item::operator==(const Cargo& other) const {
 
    try {
        const Item& other_item = dynamic_cast<const Item&>(other);
        return Cargo::operator==(other) && rarity_ == other_item.rarity_;
    } catch (std::bad_cast&) {
            return false;
    }
}