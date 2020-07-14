#pragma once

#include "fruit.hpp"

namespace {
constexpr auto kSpoilDelay = 10;
constexpr auto kDrynessPriceMultiplier = 3;
}  // namespace

class DryFruit : public Fruit {
public:
    using Fruit::Fruit;

    Fruit& operator--() override;

    // override from Cargo.Fruit
    std::string getName() const override { return "Dry " + name_; }
    size_t getPrice() const override;
    std::string oneLineDescription() const override;
    std::shared_ptr<Cargo> getShared() override { return std::make_shared<DryFruit>(DryFruit(*this)); }

    //override from Time::Observer
    void nextDay() override;

    ~DryFruit() override;

private:
    size_t spoilDelay_ = kSpoilDelay;
};
