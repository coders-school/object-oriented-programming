#pragma once

#include "Cargo.hpp"

#include <string>

struct Item : public Cargo {
    enum class Rarity {
        Common,
        Rare,
        Epic,
        Legendary
    };

private:
    Rarity rarity_;

public:
    Item(const std::string& name, const size_t amount, const size_t basePrice, const Rarity rarity);

    size_t getPrice() const override;

    std::string getName() const override;

    size_t getAmount() const override;

    size_t getBasePrice() const override;    
};
