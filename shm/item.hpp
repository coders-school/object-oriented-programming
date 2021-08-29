#pragma once

#include <iostream>
#include "cargo.hpp"

enum class Rarity {
    common = 1,
    rare = 5,
    epic = 10,
    legendary = 20
};
//Class responsible for managing Items in the game.
class Item : public Cargo {
public:
    Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity);
    ~Item() override{};

    Cargo& operator+=(const size_t amount) override;
    Cargo& operator-=(const size_t amount) override;
    bool operator==(const Cargo&) const override;

    //Methods override from Cargo class.
    size_t getPrice() const override { return basePrice_ * static_cast<size_t>(rarity_); };
    std::string getName() const override { return name_; };
    size_t getAmount() const override { return amount_; };
    size_t getBasePrice() const override { return basePrice_; };

    Rarity getRarity() const {return rarity_;};

    void setAmount(const size_t& amount) override { amount_ = amount;};
    void nextDay() override {};
private:
    Rarity rarity_;
};