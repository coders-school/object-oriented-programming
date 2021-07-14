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
    Cargo(const std::string&, size_t, size_t);

    //operators will be used to add, subtract and copare how many and  what we have
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(Cargo& cargo);

    ///simple getters
    std::string getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getPrice() const { return basePrice_; }
    size_t addAmount(size_t);
};
