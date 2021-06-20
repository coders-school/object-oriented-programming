#pragma once
#include <string>

class Cargo {
public:
    Cargo(std::string name, size_t amount, size_t basePrice)
        : name_(name)
        , amount_(amount)
        , basePrice_(basePrice)
    {}

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

    std::string getName();
    size_t getAmount();
    size_t getBasePrice();

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
