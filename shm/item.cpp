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