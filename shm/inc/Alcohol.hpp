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
    bool isExpired() const override;

    // override from Subscriber (via Cargo)
    void nextDay() override;

    size_t getPercentage() const;

protected:
    size_t percentage_;
    size_t daysUntilOnePercentEvaporates_ { 5 };
};
