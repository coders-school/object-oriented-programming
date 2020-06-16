#pragma once

#include <string>

class Cargo {
public:
    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(size_t amount) {
        amount_ -= amount;
        return *this;
    }

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
