#pragma once

#include <string>

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    //Override from Cargo
    Fruit(std::string name, size_t amount, size_t basePrice, size_t expiryDate, size_t timeElapsed);
    ~Fruit() override = default;
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;

    Fruit& operator--();
    size_t getExpiryDate() const;
    size_t getTimeElapsed() const;

private:
    size_t timeElapsed_{0};    
    const size_t expiryDate_{12};
    size_t timeToSpoil_ = expiryDate_ - timeElapsed_;
};
