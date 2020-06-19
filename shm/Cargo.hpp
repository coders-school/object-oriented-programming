#pragma once

#include <string>

class Cargo
{
public:
    Cargo& operator+=(size_t amount)
    {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(size_t amount)
    {
        amount_ -= amount;
        return *this;
    }
    Cargo() : amount_(0), basePrice_(0) {}
    Cargo(size_t amount, size_t basePrice) : amount_(amount), basePrice_(basePrice) {}

    friend bool operator==(const Cargo& lhs, const Cargo& rhs);
    friend bool operator!=(const Cargo& lhs, const Cargo& rhs);
    size_t getAmount() { return amount_; }
    size_t getBasePrice() { return basePrice_; }


protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};

bool operator==(const Cargo& lhs, const Cargo& rhs)
{
    return lhs.amount_ == rhs.amount_;
}

bool operator!=(const Cargo& lhs, const Cargo& rhs)
{
    return lhs.amount_ != rhs.amount_;
}

