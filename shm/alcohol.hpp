#pragma once
#include <iostream>
#include "cargo.hpp"



//Class responsible for representing alcohol in the game
class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage, Time *time)
        : Cargo(name, amount, basePrice, time)
        , percentage_ (percentage)
        {}

    ~Alcohol() override = default;

    // override from Cargo
    size_t getPrice() const override;
    const std::string &getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPercentage() const { return percentage_; }

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo &cargo) const override;
    void nextDay() override;

private:
    size_t percentage_;
};