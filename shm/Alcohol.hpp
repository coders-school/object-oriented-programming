#ifndef ALCOHOL_HPP
#define ALCOHOL_HPP
#include "Cargo.hpp"

// Class used to represent cargo of alcohol type carried by merchant ship
class Alcohol : public Cargo
{

private:
    size_t counter_{0};
    size_t strength_;

public:
    Alcohol(const std::string &name, size_t amount, size_t basePrice, size_t strength);
    ~Alcohol() override = default;

    size_t getPrice() const override { return (strength_ / 96.0) * basePrice_; };
    const std::string &getName() const override { return name_; }
    size_t getAmount() const override { return amount_; };
    size_t getBasePrice() const override { return basePrice_; };
    size_t getStrength() const { return strength_; }

    void nextDay() override;
};

#endif
