#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
    uint16_t timeElapsed_;
    uint16_t expiryDate_;

public:
    Fruit(uint16_t, const std::string&, uint16_t, uint16_t);
    Fruit(uint16_t, const std::string&, uint16_t, uint16_t, uint16_t);
    Fruit(uint16_t, const Fruit*);
    ~Fruit() = default;

    uint16_t getTimeElapsed() const;
    uint16_t getExpiryDate() const;

    Fruit& operator--();

    // Override from Cargo
    std::string getName() const override;
    uint16_t getAmount() const override;
    uint16_t getBasePrice() const override;
    uint16_t getPrice() const override;

    Cargo& operator+=(const uint16_t) override;
    Cargo& operator-=(const uint16_t) override;
    bool operator==(const Cargo&) const override;

    // Override from Observer
    void nextDay() override;
};