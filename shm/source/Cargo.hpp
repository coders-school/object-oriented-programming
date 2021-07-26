#pragma once

#include <string>

class Cargo {
    std::string name_;
    size_t amount_;
    size_t basePrice_;

public:
    Cargo(const std::string& name, const size_t amount, const size_t basePrice);

    bool operator==(const Cargo& cargo) const;

    Cargo& operator+=(size_t amount);

    Cargo& operator-=(size_t amount);

    std::string getName() const;

    size_t getAmount() const;

    size_t getBasePrice() const;
};
