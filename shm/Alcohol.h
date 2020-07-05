#pragma once

#include "Cargo.h"

constexpr size_t max_power = 96;

struct AlcoholData {
    std::string name_;
    size_t power_;
};

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, size_t base_price, size_t power);
    ~Alcohol() override;

    std::string getName() const override;
    size_t getAmount() const override;
    size_t getPrice() const override;
    size_t getBasePrice() const override;
    void nextDay() override;

    bool operator==(Cargo& cargo) const override;

    size_t getPower() const;

private:
    size_t power_;
};
