#pragma once

#include "cargo.hpp"

constexpr size_t maxPower{96};

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, size_t basePrice, size_t alcohol);

    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

    size_t getPrice() const override {
        return basePrice_ * (alcohol_ / maxPower);
    }

private:
    size_t alcohol_;
    bool equals(const Cargo& rhs) const override;
};
