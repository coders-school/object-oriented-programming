#pragma once

#include <string>
#include <memory>

#include "cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t timeToSpoil)
            : Cargo(name, amount, basePrice)
            , timeToSpoil_(timeToSpoil)
    {}
    
    Alcohol& operator--();
    Alcohol& operator--(int);
    bool operator==(const Cargo& alcohol) const override;
    bool operator!=(const Cargo& alcohol) const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;

    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    size_t getTimeToSpoil() const;
    size_t getTimeToSpoilLeft() const;

    Cargo* clone() override;
private:
    const size_t timeToSpoil_;
    size_t timeToSpoilLeft_ = timeToSpoil_;
};
