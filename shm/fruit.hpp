#pragma once

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    //Override from Cargo
    size_t getPrice() const override {
        return basePrice_ * (timeToSpoil_ / expiryDate_);
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
    
    Fruit& operator--() {
        if (expiryDate_ == 0) {
            return *this;
        }
        --timeToSpoil_;
        return *this;
    }

private:
    size_t timeToSpoil_ {12};
    const size_t expiryDate_ {12};
};
