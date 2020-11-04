#pragma once

#include "Cargo.hpp"

enum class Rarity {
    common = 1,
    rare = 5,
    epic = 10,
    legendary = 20
};

class Item : public Cargo {
    Rarity rarity_;

public:
    Item(uint16_t, const std::string&, uint16_t, Rarity);
    Item(uint16_t, const Item*);
    ~Item() = default;

    Rarity getRarity() const;

    // Override from Cargo
    std::string getName() const override;
    uint16_t getAmount() const override;
    uint16_t getBasePrice() const override;
    uint16_t getPrice() const override;

    Cargo& operator+=(const uint16_t) override;
    Cargo& operator-=(const uint16_t) override;
    bool operator==(const Cargo&) const override;

    // Override from Observer
    void nextDay() override;
};