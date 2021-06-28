#pragma once
#include <iostream>
#include <string>

class Cargo {
private:
    const std::string name_;
    size_t amount_;
    size_t basePrice_;

public:
    Cargo(const std::string name, size_t amount, size_t basePrice)
        : name_(name)
        , amount_(amount)
        , basePrice_(basePrice)
    {}

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(Cargo& cargo);

    std::string getName() { return name_; }
    size_t getAmount()    { return amount_; }
    size_t getPrice()     { return basePrice_; }
};
