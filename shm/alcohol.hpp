#pragma once

#include <string>

#include "cargo.hpp"

constexpr size_t maxPower{96};

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, size_t basePrice, size_t power);
    ~Alcohol() override = default;

    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;    
    size_t getPower() const;

private:
    size_t power_;
};
