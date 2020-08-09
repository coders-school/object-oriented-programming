#pragma once

#include <map>

#include "Cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity { common = 1,
                        rare = 2,
                        epic = 4,
                        legendary = 8 };

    Item(const std::string& name, uint16_t amount, uint16_t basePrice, Rarity rarity);

    Rarity getRarity() const { return rarity_; }

    //override from Cargo
      uint16_t GetPrice() const override;
    std::string GetName() const override;
    uint16_t getAmount() const override;
    // uint16_t getBasePrice() const override;
    Cargo& operator--();
    Cargo& operator+=(uint16_t amount) override;
    Cargo& operator-=(uint16_t amount) override;
    bool operator==(const Cargo&) const override;

private:
    Rarity rarity_;
};