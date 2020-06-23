#pragma once

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(const std::string& name, size_t amount, double basePrice);
    Fruit(const std::string& name, size_t amount, double basePrice, size_t timeToRotten);
    ~Fruit() override {}

    double getPrice() const override { return getBasePrice() - 0.09 * getTimeToRotten(); }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    size_t getTimeToRotten() const { return timeToRotten_; }

    void nextDay() override;

    Fruit& operator--();
    Cargo& operator+=(const size_t& amount) override;
    Cargo& operator-=(const size_t& amount) override;
    bool operator==(Cargo& fruit) const override;

private:
    size_t timeToRotten_;
};

//DryFruit?
// class DryFruit : public Fruit {
//     std::string getName() const override { return "Dry Fruit"; }
//     double getPrice() const override {
//         return 3 * basePrice_ * (1 / std::exp(timeToRotten_));}
//     DryFruit& operator--() override {
//         if (++counter_ == 10) {
//             ++time_elapsed_;
//             counter_ = 0;
//         }
//         return *this;
//     }
// private:
//     size_t counter_{0};
// };
