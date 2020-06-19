#pragma once
#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity {
        common = 1,
        rare = 2,
        epic = 4,
        legendary = 8
    };
    
    std::string getName() const override {
        return name_;
    }

    size_t getAmount() const override {
        return amount_;
    }

    size_t getBasePrice() const override {
        return basePrice_;
    }

    size_t getPrice() const override {
        return basePrice_ * static_cast<int>(rarity_);
    }

private:
    Rarity rarity_;
};