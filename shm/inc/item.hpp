#pragma once

#include <map>

#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity { common,
                        rare,
                        epic,
                        legendary };

    Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity);

    ~Item() override = default;

    Rarity getRarity() const { return rarity_; }

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPrice() const override;

protected:
    // override from Cloneable<Cargo>
    Cargo* cloneToRawPointer() override { return new Item(*this); }

private:
    Rarity rarity_;

    const std::map<Rarity, size_t> priceMultipliers_{{Rarity::common, 1},
                                                     {Rarity::rare, 2},
                                                     {Rarity::epic, 4},
                                                     {Rarity::legendary, 8}};
};
