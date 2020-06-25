#pragma once
#include "cargo.hpp"
#include <string>

constexpr size_t maxPower {96};

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, size_t basePrice, size_t power);
    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override; 
    size_t getBasePrice() const override; 

private:
    size_t power_;
};
