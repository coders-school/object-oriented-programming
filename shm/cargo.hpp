#pragma once
#include <string>
#include "TimeEffectable.hpp"

//Class responsible for representing cargo in game
class Cargo : public TimeEffectable
{
public:
    virtual Cargo &operator+=(size_t amount) = 0;
    virtual Cargo &operator-=(size_t amount) = 0;
    virtual bool operator==(const Cargo &cargo) const;

    virtual size_t getPrice() const = 0;
    virtual const std::string &getName() const = 0; // TO DO: test deleting Cargo object
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;

    void printCargo() const;
    void reduceAmount();

    Cargo() = default;
    Cargo(std::string name, size_t amount, size_t basePrice)
    :name_(name), amount_(amount), basePrice_(basePrice){};
    virtual ~Cargo() = default;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
