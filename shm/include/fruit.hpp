#pragma once

#include <cmath>

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(std::string name, size_t amount, double basePrice);
    Fruit(std::string name, size_t amount, double basePrice, size_t timeToRotten);
    ~Fruit() override {}

    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override { return price_; }
    void nextDay() override;
    size_t getTimeToRotten() const override { return timeToRotten_; }
    double setPrice ();

    Fruit& operator--() {
        if (timeToRotten_ > 0) {
            timeToRotten_--;
        }
        return *this;
    }

    Fruit& operator+=(const size_t& amount) override {
        amount_ += amount;
        return *this;
    }
    Fruit& operator-=(const size_t& amount) override {
        if (amount_ >= amount) {
            amount_ -= amount;
        }
        return *this;
    }

    bool operator==(Cargo& fruit) const override {
        return getName() == fruit.getName() &&
               getBasePrice() == fruit.getBasePrice() &&
               getPrice() == fruit.getPrice();
    }

private:
    //size_t time_elapsed_{0};
    size_t timeToRotten_;
    double price_;
};

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
