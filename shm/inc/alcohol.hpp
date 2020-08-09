
#pragma once

#include "Cargo.hpp"



class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice);
    Alcohol(const std::string& name, size_t amount, size_t basePrice, float power);
    ~Alcohol() override;

    float getPower() const { return power_; }

    //override from Cargo
    std::string GetName() const override;
    size_t getAmount() const override;
    size_t GetPrice() const override;
    std::string oneLineDescription() const override;
    Cargo& operator--();
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo&) const override;

private:
    const float power_;
    static constexpr float maxPower_=0.96;
};
