#pragma once

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(const std::string& name, size_t amount, double basePrice);
    Fruit(const std::string& name, size_t amount, double basePrice, size_t timeToRotten);
    ~Fruit() override {}

    double getPrice() const override { return getBasePrice() * static_cast<double>((getTimeToRotten()) / (getTimeToRotten() + timeElapsed_)); }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    size_t getTimeToRotten() const { return timeToRotten_; }
    void setPrice();
    std::string getInfo() const override;
    friend std::ostream& operator<<(std::ostream& os, const Cargo* cargo);
    void nextDay() override;

    Cargo& operator+=(const size_t& amount) override;
    Cargo& operator-=(const size_t& amount) override;
    bool operator==(Cargo& fruit) const override;

private:
    double price_;
    size_t timeElapsed_ = 0;
    size_t timeToRotten_;
};
