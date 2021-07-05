#pragma once

#include <string>

#include "Cargo.hpp"

constexpr size_t MAX_PERCENTAGE = 96;

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t percentage);

    // override from Cargo
    size_t getPrice() const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& alcohol) const override;

    size_t getPercentage() const;
    void setBasePrice(size_t basePrice);

private:
    size_t percentage_;
};
