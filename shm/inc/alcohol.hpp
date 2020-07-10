#pragma once

#include <string>

#include "cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(const std::string& name, size_t amount, size_t basePrice, size_t timeToSpoil)
            : Cargo(name, amount, basePrice)
            , timeToSpoil_(timeToSpoil)
    {}
    
    Alcohol& operator--();
    Alcohol& operator--(int);
    bool operator==(const Cargo& alcohol) const;
    bool operator!=(const Cargo& alcohol) const;
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    size_t getTimeToSpoil() const;
    size_t getTimeToSpoilLeft() const;

    Cargo* clone() override { return new Alcohol( *this);}

private:
    const size_t timeToSpoil_;
    size_t timeToSpoilLeft_ = timeToSpoil_;
};
