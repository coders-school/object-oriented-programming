#include "alcohol.hpp"
#include <iostream>

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

bool Alcohol::operator==(const Cargo& other) const {
 
    try {
        const Alcohol& other_alcohol = dynamic_cast<const Alcohol&>(other);
        return Cargo::operator==(other) && percentage_ == other_alcohol.percentage_;
    } catch (std::bad_cast&) {
            return false;
    }
}

void Alcohol::nextDay()
{
    basePrice_ += 2;
    std::cout << "Next day\n";
}