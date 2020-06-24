#pragma once

#include "cargo.hpp"

constexpr size_t maxPower {96};

class Alcohol : public Cargo {
public:
    //Override from Cargo
    size_t getPrice() const override {
        return basePrice_ * (power_ / maxPower);
    }
    std::string getName() const override {
        return name_;
    }
    size_t getAmount() const override {
        return amount_;
    }
    size_t getBasePrice() const override {
        return basePrice_;
    }

private:
    size_t power_;
};
