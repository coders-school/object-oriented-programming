#pragma once

#include <string>
class Cargo {
public:
    Cargo(std::string, size_t, size_t);
    std::string getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getBestPrice() const { return basePrice_; }

private:
    const std::string name_ { }; 
    size_t amount_ { 0 };
    size_t basePrice_ { 0 }; 
};