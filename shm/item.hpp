#pragma once
#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity { common = 1,
                        rare = 3,
                        epic = 6,
                        legendary = 10 };

    Item(size_t amount, const std::string& name, size_t base_price, Rarity rarity);
    ~Item() override = default;

    // override from Cargo
    size_t getPrice() const override;
    const std::string &getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

    Rarity getRarity() const { return rarity_; }

private:
    Rarity rarity_;
};