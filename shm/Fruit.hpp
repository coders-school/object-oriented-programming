#pragma once

#include "Cargo.hpp"

constexpr size_t TIME_TO_SPOIL = 10;

class Fruit : public Cargo {
public:
    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDate);
    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t expiryDate, size_t timeToSpoil);
    ~Fruit() override = default;

    size_t getPrice() const override;
    std::string getName() const override { return _name; }
    size_t getAmount() const override { return _amount; }
    size_t getBasePrice() const override { return _basePrice; }

    size_t getExpiryDate() const { return _expiryDate; }
    size_t getTimeToSpoil() const { return _timeToSpoil; }

    Fruit& operator--();

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;

    bool operator==(const Cargo& src) const override;

    // override from Observer
    void nextDay() override;
    
    std::ostream& showCargo(std::ostream& out) const override;

    size_t getMaxAmount() const override { return _maxAmount; };

private:
    size_t _timeToSpoil;
    const size_t _expiryDate;
    size_t _maxAmount = 255;
};
