#pragma once

#include <string>

class Cargo {
public:
    Cargo() = default;
    Cargo(std::string name, size_t amount, size_t basePrice);
    virtual ~Cargo() = default;

    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getPrice() const = 0;
    virtual size_t getBasePrice() const = 0;
    virtual void nextDay() = 0;

    virtual bool operator==(Cargo& cargo) const = 0;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
