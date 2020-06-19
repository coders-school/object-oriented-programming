#pragma once

#include "cargo.hpp"

class Alcohol : public Cargo {
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
        return basePrice_ * (alcohol / 96);
    } 

    private:
    size_t alcohol;
};
