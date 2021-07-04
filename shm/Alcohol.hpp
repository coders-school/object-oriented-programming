#pragma once

#include "Cargo.hpp"

constexpr auto maxPercentage = 96;
constexpr size_t alcoholBasePriceFor96percent = 100u;

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, unsigned char percentage)
        : Cargo(name, amount, alcoholBasePriceFor96percent), percentage_{percentage} 
    {
        if (percentage_ > maxPercentage) {
            percentage_ = maxPercentage;
        }
    }

    size_t getPrice() const override {
        return static_cast<size_t>(basePrice_ * percentage_ / static_cast<double>(maxPercentage));
    }

    bool operator==(const Cargo& other) const override {
        if(auto otherItem = dynamic_cast<const Alcohol*>(&other)){
            return name_ == otherItem->getName()
            and percentage_ == otherItem->percentage_;
        }
        return false;
    }

    std::unique_ptr<Cargo> split(size_t amountPart) override {
        if (!amountPart or amountPart > amount_) {
            return {};
        }
        *this -= amountPart;
        return std::make_unique<Alcohol>(name_, amountPart, percentage_);
    }

    static size_t alcoholBasePriceFor96percent_;

protected:
    unsigned char percentage_ = 0;
};

size_t Alcohol::alcoholBasePriceFor96percent_ = alcoholBasePriceFor96percent;
