#pragma once

#include "fruit.hpp"

namespace {
constexpr auto kSpoilDelay = 10;
constexpr auto kDrynessPriceMultiplier = 3;
}  // namespace

class DryFruit : public Fruit {
    using Fruit::Fruit;

    Fruit& operator--() override;

    // override from Cargo.Fruit
    std::string getName() const override { return "Dry " + name_; }
    size_t getPrice() const override;

private:
    size_t spoilDelay_ = kSpoilDelay;
};
