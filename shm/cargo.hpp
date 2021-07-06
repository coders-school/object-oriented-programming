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
    bool operator==(const Cargo&) const;

    std::string getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;
    
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
