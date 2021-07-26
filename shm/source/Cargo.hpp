#pragma once

#include "Observer.hpp"

#include <string>

class Cargo : Observer {
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;

public:
    // Observer:
    virtual void nextDay() override = 0;

    // Cargo Interface:
    Cargo(const std::string& name, const size_t amount, const size_t basePrice);

    virtual size_t getPrice() const = 0;

    virtual std::string getName() const = 0;

    virtual size_t getAmount() const = 0;

    virtual size_t getBasePrice() const = 0;    

    bool operator==(const Cargo& cargo) const;

    Cargo& operator+=(size_t amount);

    Cargo& operator-=(size_t amount);
};
