
#pragma once

#include "Cargo.hpp"



class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, uint16_t amount, uint16_t basePrice);
    Alcohol(const std::string& name, uint16_t amount, uint16_t basePrice, float power);
    ~Alcohol() override;

    float getPower() const { return power_; }

    //override from Cargo
    std::string getName() const override;
    uint16_t getAmount() const override;
    uint16_t getPrice() const override;
    Cargo& operator--();
    Cargo& operator+=(uint16_t amount) override;
    Cargo& operator-=(uint16_t amount) override;
    bool operator==(const Cargo&) const override;

private:
    const float power_;
    static constexpr float maxPower_=0.96;
};
