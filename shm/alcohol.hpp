#pragma once

#include "cargo.hpp"

constexpr size_t maxPower{96};

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, size_t basePrice, size_t alcoholPower);

    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPrice() const override {
        return basePrice_ * (alcoholPower_ / maxPower);
    }

    //override from Cargo
    void nextDay() override;

private:
    size_t alcoholPower_{};
    bool equals(const Cargo& rhs) const override;
};
