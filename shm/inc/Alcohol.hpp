#pragma once

#include <string>

#include "Cargo.hpp"

constexpr size_t MAX_PERCENTAGE = 96;

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage);

    //override Cargo
    size_t getPrice() const override {
        return basePrice_ * percentage_ / MAX_PERCENTAGE;
    }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& alcohol) const override;

    size_t getPercentage() const { return percentage_; }

    void setBasePrice(size_t basePrice) { basePrice_ = basePrice; } 

private:
    size_t percentage_;
};
