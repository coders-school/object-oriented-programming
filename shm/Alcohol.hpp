#pragma once

#include "Cargo.hpp"

constexpr size_t MAX_POWER = 96;

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice);
    Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t power);
    ~Alcohol() override = default;

    size_t getPrice() const override;
    std::string getName() const override { return _name; }
    size_t getAmount() const override { return _amount; }
    size_t getBasePrice() const override { return _basePrice; }

    size_t getPower() const { return _power; }

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;

    bool operator==(const Cargo& src) const override;

    std::ostream& showCargo(std::ostream& out) const override;

private:
    const size_t _power;
    size_t _maxAmount = 255;
};
