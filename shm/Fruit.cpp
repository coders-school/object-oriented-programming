#include "Fruit.hpp"

void Fruit::Print() const
{
}
std::string Fruit::GetName() const
{
    return name_;
};

size_t Fruit::GetPrice() const
{
    return Fruit::GetBasePrice() * Fruit::GetAmount();
}

size_t Fruit::GetAmount() const
{
    return amount_;
}

size_t Fruit::GetBasePrice() const
{
    return base_price_;
}

Fruit& Fruit::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}

Fruit& Fruit::operator-=(size_t amount)
{
    amount_ -= amount;
    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const
{
    if (typeid(cargo) == typeid(Fruit))
    {
        const auto* pFruit = dynamic_cast<const Fruit*>(&cargo);
        return name_ == pFruit->GetName() && amount_ == pFruit->GetAmount() && base_price_ == pFruit->GetBasePrice()
               && expiry_date_ == pFruit->GetExpiryDate() && time_elapsed_ == pFruit->GetTimeElapsed();
    }
    return false;
}

bool Fruit::operator!=(const Cargo& cargo) const
{
    return not operator==(cargo);
}

size_t Fruit::GetTimeElapsed() const
{
    return time_elapsed_;
}

size_t Fruit::GetExpiryDate() const
{
    return expiry_date_;
}

Fruit::Fruit(size_t amount, const std::string& name, size_t base_price, size_t expiry_date)
    : Cargo(amount, name, base_price), expiry_date_(expiry_date)
{
}

Fruit::Fruit(size_t amount, const std::string& name, size_t base_price, size_t expiry_date, size_t time_elapsed)
    : Cargo(amount, name, base_price), expiry_date_(expiry_date), time_elapsed_(time_elapsed)
{
}
