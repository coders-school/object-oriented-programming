#pragma once

#include "Observer.hpp"
#include "string"

class Cargo : public Observer {
protected:
    std::string name_;
    uint16_t amount_;
    uint16_t basePrice_;

public:
    Cargo() = default;
    Cargo(uint16_t, const std::string&, uint16_t);
    virtual ~Cargo() = default;

    virtual std::string getName() const = 0;
    virtual uint16_t getAmount() const = 0;
    virtual uint16_t getBasePrice() const = 0;
    virtual uint16_t getPrice() const = 0;

    virtual Cargo& operator+=(const uint16_t) = 0;
    virtual Cargo& operator-=(const uint16_t) = 0;
    virtual bool operator==(const Cargo&) const = 0;
};