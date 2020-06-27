#pragma once

#include "Cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity {
        common = 1,
        rare = 3,
        epic = 10,
        legendary = 25
    };

    Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity);
    ~Item() override = default;

    Rarity getRarity() const { return _rarity; }

    size_t getPrice() const override;
    std::string getName() const override { return _name; }
    size_t getAmount() const override { return _amount; }
    size_t getBasePrice() const override { return _basePrice; }

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;

    bool operator==(const Cargo& src) const override;

private:
    const Rarity _rarity{Rarity::epic};
    size_t _maxAmount = 255;
};
