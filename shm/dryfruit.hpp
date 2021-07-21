#pragma once
#include "fruit.hpp"

class DryFruit : public Fruit {
public:
    // override from Cargo
    const std::string& getName() const override { return name_; } // "Dry fruit"
    size_t getPrice() const override;

    // override from Fruit
    Cargo& operator--() override;

private:
    size_t counter_{0};
};