#pragma once

#include "cargo.hpp"

class Fruit : public Cargo
{
public:
    Fruit(size_t amount, std::string name, size_t basePrice, size_t expiringTime, size_t data)
        : Cargo(name, amount, basePrice)
        , expiringTime_(expiringTime)
        ,data_(data) 
        {}
    ~Fruit();

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& fruit) const override;
    Fruit& operator--();
    Fruit& operator--(int);

    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;

    size_t getExpitingTime() const;
    size_t getData() const;

private:
    size_t expiringTime_ {0};
    size_t data_ ;
};


