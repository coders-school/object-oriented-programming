#include "Cargo.hpp"

Cargo& Cargo::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}
Cargo& Cargo::operator-=(size_t amount)
{
    amount_ -= amount;
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
    return lhs.amount_ != rhs.amount_;
}
