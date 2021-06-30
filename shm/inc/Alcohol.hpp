#pragma once

#include <string>

#include "Cargo.hpp"

constexpr size_t basePrice = 96;

class Alcohol : public Cargo {
public:
    Alcohol(const std::string&, size_t, size_t, size_t);
    ~Alcohol() override;

    size_t getPrice() const override; { return basePrice_ * percentage_ / 96; }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBestPrice() const override { return basePrice_; }

    size_t getPercentage() const { return percentage_; }

    void setBasePrice(size_t basePrice) { basePrice_ = basePrice; } 

private:
    size_t percentage;
};