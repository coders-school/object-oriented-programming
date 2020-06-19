#pragma once

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(const std::string& name,
          size_t amount,
          size_t basePrice,
          size_t expiryDate,
          size_t timeElapsed);

    // override from Cargo
    size_t getPrice() const override;
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }

    Fruit& operator--();

private:
    size_t timeElapsed_{0};
    size_t expiryDate_;
};
