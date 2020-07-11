#include "alcohol.hpp"

size_t Alcohol::getPrice() const
{
    return static_cast<size_t>(static_cast<size_t>(basePrice_) * (strength_ / MAX_STRENGTH));
}

std::string Alcohol::getName() const
{
    return name_;
}
size_t Alcohol::getAmount() const
{
    return amount_;
}
size_t Alcohol::getBasePrice() const
{
    return basePrice_;
}
size_t Alcohol::getStrength() const
{
    return strength_;
}

Alcohol& Alcohol::operator--()
{
    if (amount_ > 0) {
        --amount_;
    }
    return *this;
}
Alcohol& Alcohol::operator--(int)
{
    Alcohol& temp(*this);
    if (amount_ > 0) {
        operator--();
    }
    return temp;
}
bool Alcohol::operator==(const Cargo& cargo) const
{
    if (typeid(cargo) == typeid(Alcohol)) {
        const Alcohol* alcohol = static_cast<const Alcohol*>(&cargo);
        return name_ == alcohol->getName() &&
               amount_ == alcohol->getAmount() &&
               basePrice_ == alcohol->getBasePrice() &&
               strength_ == alcohol->getStrength();
    }
    return false;
}
bool Alcohol::operator!=(const Cargo& cargo) const
{
    if (typeid(cargo) == typeid(Alcohol)) {
        const Alcohol* alcohol = static_cast<const Alcohol*>(&cargo);
        return !(this == alcohol);
    }
    return false;
}
Cargo& Alcohol::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}
Cargo& Alcohol::operator-=(size_t amount)
{
    if (amount <= amount_) {
        amount_ -= amount;
        return *this;
    }
    return *this;
}

std::unique_ptr<Cargo> Alcohol::clone()
{
    std::unique_ptr<Alcohol> alcohol = std::make_unique<Alcohol>(*this);
    return alcohol;
}

void Alcohol::nextDay()
{
    return;
}
