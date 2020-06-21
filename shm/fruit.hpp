#pragma once
#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit& operator--();

    std::string getName() const override {
        return name_;
    }

    size_t getAmount() const override {
        return amount_;
    }

    size_t getBasePrice() const override {
        return basePrice_;
    }

    size_t getPrice() const override {
        return basePrice_ * (timeToExpire_ / expiryDate_);
    }

private:
    size_t timeToExpire_;
    const size_t expiryDate_{10};
};