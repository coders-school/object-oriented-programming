#pragma once

#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity { common = 1, rare = 3, epic = 6, legendary = 10 };

    Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity);
    ~Item() override = default;

    // override from Cargo
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& other) const override;
    // override from Observer
    void nextDay() override {}

    size_t getPrice() const override { return basePrice_ * static_cast<size_t>(rarity_); }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

private:
    const Rarity rarity_;
};
