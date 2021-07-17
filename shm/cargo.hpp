#pragma once
#include <string>

//Class responsible for representing cargo in game
class Cargo
{
public:
    Cargo &operator+=(size_t amount);
    Cargo &operator-=(size_t amount);
    bool operator==(const Cargo &cargo) const;

    const std::string& getName() {return name_;} // TO DO: test deleting Cargo object
    size_t getAmount() {return amount_;}
    size_t getBasePrice() {return basePrice_;}
    Cargo () = default;
    Cargo(std::string name, size_t amount, size_t basePrice);
    void printCargo() const;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
