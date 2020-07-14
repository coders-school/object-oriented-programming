#pragma once

#include <map>

#include "cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity { common = 1,
                        rare = 2,
                        epic = 4,
                        legendary = 8 };
    static const std::map<Item::Rarity, std::string> rarityStringMapping;

    Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity);

    ~Item() override;

    Rarity getRarity() const { return rarity_; }

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPrice() const override;
    std::string oneLineDescription() const override;
    bool operator==(const Cargo& cargoToCheck) const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    std::shared_ptr<Cargo> getShared() override { return std::make_shared<Item>(Item(*this)); }

    //override from Time::Observer
    void nextDay() override;

private:
    Rarity rarity_;
};
