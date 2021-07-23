#pragma once
#include <string>
#include "TimeEffectable.hpp"

//Class responsible for representing cargo in game
class Cargo : public TimeEffectable
{
public:
    virtual Cargo &operator+=(size_t amount);
    virtual Cargo &operator-=(size_t amount);
    virtual bool operator==(const Cargo &cargo) const;

    virtual size_t getPrice() const = 0;
    virtual const std::string &getName() const { return name_; } // TO DO: test deleting Cargo object
    virtual size_t getAmount() const { return amount_; }
    virtual size_t getBasePrice() const { return basePrice_; }

    void printCargo() const;
    std::string getCargoInfo();
    void reduceAmount();

    Cargo() = default;
    Cargo(std::string name, size_t amount, size_t basePrice);
    virtual ~Cargo() = default;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
