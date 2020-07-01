#pragma once

#include <string>

#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity {
        common = 1,
        rare = 2,
        epic = 4,
        legendary = 8
    };

    Item(std::string name, size_t amount, size_t basePrice, Rarity rarity);

    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPrice() const override {
        return basePrice_ * static_cast<int>(rarity_);
    }
    //override from Cargo
    void nextDay() override;

    std::string checkRarity();

private:
    Rarity rarity_{};
    bool equals(const Cargo& rhs) const override;
};
