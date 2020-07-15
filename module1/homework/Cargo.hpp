#pragma once

#include <string>

class Cargo {
    std::string name_;
    size_t amount_;
    size_t basePrice_;

public:
    Cargo(const std::string&, size_t, size_t);

    Cargo& operator+=(const size_t);
    Cargo& operator-=(const size_t);
    bool operator==(const Cargo&) const;

    std::string getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;
};