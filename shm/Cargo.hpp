#pragma once

#include <string>

class Cargo {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice)
        : name_(name), amount_(amount), basePrice_(basePrice) {}

    const std::string& getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getBasePrice() const { return basePrice_; }

    Cargo& operator+=(const size_t amount);
    Cargo& operator-=(const size_t amount);
    bool operator==(const Cargo& cargo);

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
