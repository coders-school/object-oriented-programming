#pragma once

#include <string>

#include "shm/inc/Cargo.hpp"

constexpr size_t DAYS_TO_ROTTEN { 10 };

class Fruit : public Cargo {
public:
    Fruit(const std::string& name, size_t amount, size_t basePrice);

// Override from Cargo class
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    virtual size_t getPrice() const override;

    Cargo& operator+=(const size_t amount) override;
    Cargo& operator-=(const size_t amount) override;
    bool operator==(const Cargo& cargo) const override;
    virtual Fruit& operator--();

protected:
    size_t rottenTime_ { 10 };
};
