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
    size_t getRottenTime() const { return rottenTime_; }
    Cargo& operator+=(const size_t amount) override;
    Cargo& operator-=(const size_t amount) override;
    bool operator==(const Cargo& cargo) const override;
    bool isExpired() const override;

    // override from Subscriber (via Cargo)
    void nextDay() override;

    virtual Fruit& operator--();
    virtual size_t getTimeElapsed() const { return timeElapsed_; }

protected:
    size_t rottenTime_{ DAYS_TO_ROTTEN };
    size_t timeElapsed_{ };
};
