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

    //Methods override from Cargo class.
    size_t getPrice() const override { return basePrice_ * static_cast<size_t>(rarity_); };

    Rarity getRarity() const { return rarity_; };

    void nextDay() override {};

    std::shared_ptr<Cargo> clone(const size_t &) const;

    void setTime(const std::shared_ptr<Time>&) override {};

    void detachingObserver() override {};
private:
    Rarity rarity_;
};
