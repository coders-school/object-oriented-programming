#pragma once

#include "Cargo.hpp"

#include <string>

class Fruit : public Cargo {
    const double maxFreshness_;
    double freshness_;

public:
    Fruit(const std::string& name, const size_t amount, const size_t basePrice);

    virtual Fruit& operator--();
    
    virtual size_t getPrice() const override;

    virtual std::string getName() const override;

    size_t getAmount() const override;

    size_t getBasePrice() const override;   

    void nextDay() override;  
};
