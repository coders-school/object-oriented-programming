#pragma once

#include "cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, double basePrice);
    Alcohol(const std::string& name, size_t amount, double basePrice, double volume);
    ~Alcohol() override {}

    double getPrice() const override;
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    double getVolume() const { return volume_; }
    std::string getInfo() const override;

    void nextDay() override {volume_ -= 0.05;}

    Cargo& operator+=(const size_t& amount) override;
    Cargo& operator-=(const size_t& amount) override;
    bool operator==(Cargo& alcohol) const override;

private:
    double volume_ = 0.96;
};
