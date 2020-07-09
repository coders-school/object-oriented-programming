#pragma once

#include <string>

class Cargo {
public:
    std::string getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;

    Cargo& operator+=(const size_t amount);
    Cargo& operator-=(const size_t amount);
    bool operator==(const Cargo& cargo);

private:
    const std::string name_;
    size_t amount_;
    size_t basePrice_;
};
