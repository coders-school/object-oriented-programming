#pragma once

#include "Cargo.hpp"

#include <string>

class Alcohol : public Cargo {
    size_t voltage_;

public:
    Alcohol(const std::string& name, const size_t amount, const size_t basePrice, const size_t voltage);

    size_t getPrice() const override;

    std::string getName() const override;

    size_t getAmount() const override;

    size_t getBasePrice() const override;    
};
