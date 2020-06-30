#include "Cargo.hpp"

Cargo::Cargo() : amount_(0), basePrice_(0) {}
Cargo::Cargo(size_t amount, size_t basePrice) : amount_(amount), basePrice_(basePrice) {}




Cargo& Cargo::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}
Cargo& Cargo::operator-=(size_t amount)
{
    if(amount_ >= amount) amount_ -= amount;
    return *this;
}

size_t Cargo::getAmount() const
{
    return amount_;
}
size_t Cargo::getBasePrice() const
{
    return basePrice_;
}

bool operator==(const Cargo& lhs, const Cargo& rhs)
{
    return lhs.amount_ == rhs.amount_;
}

bool operator!=(const Cargo& lhs, const Cargo& rhs)
{
    return !(lhs == rhs);
}
