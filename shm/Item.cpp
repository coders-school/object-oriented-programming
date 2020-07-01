#include "Item.hpp"

Item::Item(size_t amount, const std::string& name, size_t base_price, Rarity rarity)
    : Cargo(amount, name, base_price), rarity_(rarity)
{
}

void Item::Print() const
{
}

std::string Item::GetName() const
{
    return name_;
};

size_t Item::GetPrice() const
{
    return Item::GetBasePrice() * Item::GetAmount();
}

size_t Item::GetAmount() const
{
    return amount_;
}

size_t Item::GetBasePrice() const
{
    return base_price_;
}

Item& Item::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}

Item& Item::operator-=(size_t amount)
{
    amount_ -= amount;
    return *this;
}

bool Item::operator==(const Cargo& cargo) const
{
    if (typeid(cargo) == typeid(Item))
    {
        const Item* pItem = dynamic_cast<const Item*>(&cargo);
        return name_ == pItem->GetName() && amount_ == pItem->GetAmount() && base_price_ == pItem->GetBasePrice()
               && rarity_ == pItem->GetRarity();
    }
    return false;
}

bool Item::operator!=(const Cargo& cargo) const
{
    return not operator==(cargo);
}
Item::Rarity Item::GetRarity() const
{
    return rarity_;
}
