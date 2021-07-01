#pragma once
#include <string>

//class to store cargos which will be used to sell bought and transport on ship
//in future will be used as base class to create specilised carogs like coal, wood, wool, etc.
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
//operators will be used to add, subtract and copare how many and  what we have
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(Cargo& cargo);

///simple getters
    std::string getName()   { return name_; }
    size_t getAmount()      { return amount_; }
    size_t getPrice()       { return basePrice_; }

};
