#pragma once

#include "cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, double basePrice);
    Alcohol(std::string name, size_t amount, double basePrice, double volume);
    ~Alcohol() override {}

    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override { return price_; }
    void nextDay() override {}
    size_t getTimeToRotten() const {}
    double getVolume() const { return volume_; }
    double setPrice() const;

    Alcohol& operator+=(const size_t& amount) override {
        amount_ += amount;
        return *this;
    }
    Alcohol& operator-=(const size_t& amount) override {
        if (amount_ >= amount) {
            amount_ -= amount;
        }
        return *this;
    }

    bool operator==(Cargo& alcohol) const override {
        return getName() == alcohol.getName() &&
               getBasePrice() == alcohol.getBasePrice() &&
               getPrice() == alcohol.getPrice();
    }

private:
    double volume_ = 0.96;
    double price_;
};
