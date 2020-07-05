#pragma once

#include <map>

#include "Cargo.h"
#include "Time.h"

enum class Rarity {
    common = 1,
    rare = 3,
    epic = 5,
    legendary = 10,
};

std::map<Rarity, std::string> rarityMap{
    {Rarity::common, "Common"},
    {Rarity::rare, "Rare"},
    {Rarity::epic, "Epic"},
    {Rarity::legendary, "Legendary"},
};

struct ItemData {
    std::string name_;
    Rarity rarity_;
};

class Item : public Cargo {
public:
    Item(std::string name, size_t amount, size_t base_price, Time* time, Rarity rarity);
    ~Item() override;

    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    size_t getPrice() const override;
    void nextDay() override;
    std::string getDescription() const override;

    bool operator==(Cargo& cargo) const override;

    Rarity getRarity() const;

private:
    Rarity rarity_;
};
