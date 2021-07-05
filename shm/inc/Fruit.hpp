#pragma once

#include <string>

#include "shm/inc/Cargo.hpp"

constexpr size_t DAYS_TO_ROTTEN{ 10 };

class Fruit : public Cargo {
public:
    Fruit(const std::string& name, size_t amount, size_t basePrice);
    virtual ~Fruit() = default;

    // override from Cargo class
    virtual size_t getPrice() const override;
    Cargo& operator+=(const size_t amount) override;
    Cargo& operator-=(const size_t amount) override;
    bool operator==(const Cargo& cargo) const override;
    virtual Fruit& operator--();

protected:
    size_t rottenTime_{ DAYS_TO_ROTTEN };
};
