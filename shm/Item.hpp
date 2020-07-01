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

    std::string getRarityStr() const {
        if (_rarity == Rarity::common)
            return "common";
        if (_rarity == Rarity::rare)
            return "rare";
        if (_rarity == Rarity::epic)
            return "epic";
        if (_rarity == Rarity::legendary)
            return "legendary";
        return "common";
    }

    static Rarity ChooseRarity(size_t code);
    
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

    // override from Observer
    void nextDay() override;

    std::ostream& showCargo(std::ostream& out) const override;

    size_t getMaxAmount() const override { return _maxAmount; };

private:
    const Rarity _rarity{Rarity::epic};
    size_t _maxAmount = 255;
};
