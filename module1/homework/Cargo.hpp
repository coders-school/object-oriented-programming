#pragma once

#include <string>

class Cargo {
    std::string name_;
    uint16_t amount_;
    uint16_t basePrice_;

public:
    Cargo(const std::string&, uint16_t, uint16_t);

    Cargo& operator+=(const uint16_t);
    Cargo& operator-=(const uint16_t);
    bool operator==(const Cargo&) const;

    std::string getName() const;
    uint16_t getAmount() const;
    uint16_t getBasePrice() const;
};