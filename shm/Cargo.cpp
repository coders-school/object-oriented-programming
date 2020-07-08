#include "Cargo.hpp"
#include "ShmExceptions.hpp"

Cargo::Cargo() : amount_(0), basePrice_(0)
{
}
Cargo::Cargo(size_t amount, size_t basePrice) : amount_(amount), basePrice_(basePrice)
{
}

Cargo& Cargo::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}
Cargo& Cargo::operator-=(size_t amount)
{

    if (amount_ >= amount)
        amount_ -= amount;
    else
        throw AmountException("Not enough Cargo!");
    return *this;
}



bool operator==(const Cargo& lhs, const Cargo& rhs)
{
    return lhs.amount_ == rhs.amount_ && lhs.name_ == rhs.name_ && lhs.basePrice_ == rhs.basePrice_;
}

bool operator!=(const Cargo& lhs, const Cargo& rhs)
{
    return !(lhs == rhs);
}
