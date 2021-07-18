#include "alcohol.hpp"

size_t Alcohol::getPrice() const
{
    return basePrice_ * percentage_ / 96;
}

Cargo &Alcohol::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}

Cargo &Alcohol::operator-=(size_t amount)
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

/*bool Alcohol::operator==(const Cargo &cargo) const
{
    return name_ == cargo.name_ && amount_ == cargo.amount_ && basePrice_ == cargo.basePrice_;
}*/