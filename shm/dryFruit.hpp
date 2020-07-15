#pragma once

#include <memory>
#include <string>

#include "fruit.hpp"
#include "timeSHM.hpp"

constexpr size_t drySpoilDelay = 10;
constexpr size_t drynessPriceMultiplier = 3;

class DryFruit : public Fruit{
public:
    using Fruit::Fruit;

    Fruit& operator--();

    // override from Cargo
    virtual std::shared_ptr<Cargo> Clone() override { return std::make_shared<DryFruit>(*this); }
    // Override from Observer
    void nextDay() override;


    // Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override { return "Dry " + Fruit::getName(); }


private:
    size_t spoilDelay_ = drySpoilDelay;
};
