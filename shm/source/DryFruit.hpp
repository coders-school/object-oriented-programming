#pragma once

#include "Fruit.hpp"

#include <string>

class DryFruit : public Fruit {
    size_t freshnessModifier_;

public:
    DryFruit(const std::string& name, const size_t amount, const size_t basePrice);

    DryFruit& operator--() override;
    
    size_t getPrice() const override;

    std::string getName() const override;
};
