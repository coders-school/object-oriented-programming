#pragma once

#include "cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t base_price, size_t percentage);

    // override from Cargo
    size_t getPrice() const override { return basePrice_ * percentage_ / maxPercentage_; }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

private:
    size_t percentage_;
    const size_t maxPercentage_{96};
};
