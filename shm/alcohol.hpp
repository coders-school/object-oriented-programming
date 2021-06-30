#pragma once 

#include "cargo.hpp"

constexpr auto max = 96;

class Alcohol : public Cargo
{

public:
    Alcohol(size_t amount, std::string name, size_t basePrice, size_t percentegs)
        : Cargo(name, amount, basePrice)
        , percentages_(percentegs)
        {}
    ~Alcohol();

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& alcohol) const override;

    Alcohol& operator--();
    Alcohol& operator--(int);

    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    size_t getPercentages() const;

private:
    size_t percentages_;   
};

