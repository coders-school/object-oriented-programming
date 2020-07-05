#pragma once

#include "Cargo.h"

enum class Rarity {
    common = 1,
    rare = 3,
    epic = 5,
    legendary = 10,
};

struct ItemData {
    std::string name_;
    Rarity rarity_;
};

class Item : public Cargo {
public:
    Item(std::string name, size_t amount, size_t base_price, Rarity rarity);
    ~Item() override;

    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    size_t getPrice() const override;
    void nextDay() override;

    bool operator==(Cargo& cargo) const override;

    Rarity getRarity() const;

private:
    Rarity rarity_;
};
