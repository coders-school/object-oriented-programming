#pragma once

#include <string>

#include "cloneable.hpp"

class Cargo : public Cloneable<Cargo> {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice);
    virtual ~Cargo() = default;

    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getPrice() const = 0;
    virtual size_t getBasePrice() const = 0;

    bool operator==(const Cargo& cargoToCheck) const;
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
