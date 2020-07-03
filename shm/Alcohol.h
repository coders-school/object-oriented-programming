#pragma once

#include "Cargo.h"

constexpr size_t max_power = 96;

class Alcohol : public Cargo {
public:
    Alcohol(std::string& name, size_t amount, size_t base_price, size_t power);
    ~Alcohol() override;

    size_t getPrice() const override;

    bool operator==(const Cargo& cargo) const override;

    size_t getPower() const;

private:
    size_t power_;
};
