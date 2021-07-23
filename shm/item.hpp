#pragma once
#include "cargo.hpp"

enum class Rarity
    {
        common = 1,
        rare = 3,
        epic = 6,
        legendary = 10
    };
    
class Item : public Cargo
{
public:

    Item(const std::string &name, size_t amount, size_t basePrice, Rarity rarity)
        : Cargo(name, amount, basePrice), rarity_{rarity} {}
    ~Item() override = default;

    // override from Cargo
    size_t getPrice() const override;
    const std::string &getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    Rarity getRarity() const { return rarity_; }

    Cargo &operator+=(size_t amount) override;
    Cargo &operator-=(size_t amount) override;
    bool operator==(const Cargo &cargo) const override;

    void nextDay() override;

private:
    Rarity rarity_;
};