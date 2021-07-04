#pragma once

#include <string>

#include "Cargo.hpp"

constexpr size_t basePrice = 96;

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t, size_t basePrice);
    ~Alcohol() override;

    //override Cargo
    size_t getPrice() const override { return basePrice_ * percentage_ / 96; }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

    size_t getPercentage() const { return percentage_; }

    void setBasePrice(size_t basePrice) { basePrice_ = basePrice; } 

private:
    size_t percentage_;
};
