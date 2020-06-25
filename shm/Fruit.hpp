#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    size_t getPrice() const override;
    std::string getName() const override { return _name; }
    size_t getAmount() const override { return _amount; }
    size_t getBasePrice() const override { return _basePrice; }

    Fruit& operator--();

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;

    bool operator==(const Cargo& src) const override;
    bool operator!=(const Cargo& src) const override;

private:
    size_t _timeToSpoil{10};
    const size_t _expiryDate{10};
    size_t _maxAmount = 255;
};
