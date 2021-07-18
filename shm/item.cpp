#include "item.hpp"

size_t Item::getPrice() const
{
    return basePrice_ * static_cast<int>(rarity_);
}