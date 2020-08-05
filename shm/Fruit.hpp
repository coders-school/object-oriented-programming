#pragma once

#include "Cargo.hpp"

constexpr size_t expirationDays{10};

class Fruit : public Cargo {
private:
    size_t daysToRot_{10};

public:
    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t daysToRot);

    //override from Observer
    void nextDay() override { --(*this); }

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPrice() const override {
        return static_cast<size_t>(basePrice_ * daysToRot_ / expirationDays);
    }
    size_t getUniqueStat() const override { return daysToRot_; }

    Cargo& operator+=(const size_t amount) override;
    Cargo& operator-=(const size_t amount) override;
    bool operator==(const Cargo& cargo) const override;
    bool operator!=(const Cargo& cargo) const override;

    Fruit& operator--();
    size_t getExpirationDays() const { return expirationDays; }

};
