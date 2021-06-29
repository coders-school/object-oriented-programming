#pragma once 
 
#include "Cargo.hpp"
 
class Alcohol : public Cargo {
public:
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
 
private:
    size_t percentageOfAlcohol;
 
};

