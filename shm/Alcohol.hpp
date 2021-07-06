#pragma once

#include "Cargo.hpp"

constexpr auto maxPercentage = 96;
constexpr size_t alcoholBasePriceFor96percent = 100u;

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, unsigned char percentage);
    ~Alcohol() override = default;

    size_t getPrice() const override;
    bool operator==(const Cargo& other) const override;
    std::unique_ptr<Cargo> split(size_t amountPart) override;

    static size_t alcoholBasePriceFor96percent_;

protected:
    unsigned char percentage_ = 0;
};
