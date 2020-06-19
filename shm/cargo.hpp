#pragma once

#include <string>

class Cargo {
public:
    Cargo(std::string name, size_t amount, size_t price);
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo& rhs) const;

    std::string getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getBasePrice() const { return basePrice_; }

private:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
