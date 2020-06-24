#pragma once

#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity {
        common = 1,
        rare = 3,
        epic = 8,
        legendary = 50,
    };

    //Override from Cargo
    size_t getPrice() const override {
        return basePrice_ * static_cast<int>(rarity_);
    }
    std::string getName() const override {
        return name_;
    }
    size_t getAmount() const override {
        return amount_;
    }
    size_t getBasePrice() const override {
        return basePrice_;
    }

private:
    const size_t rarity_;
};
