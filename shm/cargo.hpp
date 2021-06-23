#pragma once
#include <string>

class Cargo
{
public:
    Cargo &operator+=(size_t amount);
    Cargo &operator-=(size_t amount);
    bool operator==(const Cargo &cargo) const;

    std::string getName() {return name_;}
    size_t getAmount() {return amount_;}
    size_t getBasePrice() {return basePrice_;}

    Cargo(std::string name, size_t amount, size_t basePrice)
    :name_(name), amount_(amount), basePrice_(basePrice){}

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
