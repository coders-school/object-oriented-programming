#pragma once

#include <string>

class Cargo {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice_) 
        : name_(name)
        , amount_(amount)
        , basePrice_(basePrice)
    {}

    virtual ~Cargo();

    virtual Cargo& operator+=(const size_t) = 0;
    virtual Cargo& operator-=(const size_t) = 0;
    virtual bool operator==(const Cargo&) const = 0;

    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBestPrice() const = 0;


private:
    const std::string name_; 
    size_t amount_ {};
    size_t basePrice_ {}; 
};
