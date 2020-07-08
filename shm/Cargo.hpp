#pragma once

#include <string>
#include <vector>

class Cargo
{
public:
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    Cargo();
    Cargo(size_t amount, size_t basePrice);

    friend bool operator==(const Cargo& lhs, const Cargo& rhs);
    friend bool operator!=(const Cargo& lhs, const Cargo& rhs);
    [[nodiscard]] size_t getAmount() const { return amount_; }
    [[nodiscard]] size_t getBasePrice() const { return basePrice_; }

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
