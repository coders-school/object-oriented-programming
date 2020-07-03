#pragma once

#include "Cargo.h"

enum class Rarity {
    common = 1,
    rare = 3,
    epic = 5,
    legendary = 10,
};

class Item : public Cargo {
public:
    Item(std::string& name, size_t amount, size_t base_price, Rarity rarity);
    ~Item() override;

    size_t getPrice() const override;

    bool operator==(const Cargo& cargo) const override;

    Rarity getRarity() const;

private:
    Rarity rarity_;
};
