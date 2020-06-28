#pragma once

#include "cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t base_price, size_t percentage);
    ~Alcohol() override = default;

    // override from Cargo
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& other) const override;
    // override from Observer
    void nextDay() override {}

    size_t getPrice() const override;
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

private:
    size_t percentage_;
    const size_t maxPercentage_{96};
};
