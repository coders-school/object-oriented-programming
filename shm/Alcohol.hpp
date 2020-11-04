#pragma once

#include "Cargo.hpp"

constexpr uint16_t MAX_POWER = 96;

class Alcohol : public Cargo {
    uint16_t percentage_;

public:
    Alcohol(uint16_t, const std::string&, uint16_t, uint16_t);
    Alcohol(uint16_t, const Alcohol*);
    ~Alcohol() = default;

    uint16_t getPercentage() const;

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