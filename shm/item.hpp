#pragma once

#include <string>

#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity {
        common = 1,
        rare = 3,
        epic = 8,
        legendary = 50,
    };

    Item(std::string name, size_t amount, size_t basePrice, Rarity rarity);
    ~Item() override = default;

    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    Rarity getRarity() const;

private:
    Rarity rarity_;
};
