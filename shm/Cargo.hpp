#pragma once

#include <string>

class Cargo {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice);

    Cargo& operator+=(const size_t amount);
    Cargo& operator-=(const size_t amount);

    bool operator==(const Cargo& src) const;
    bool operator!=(const Cargo& src) const;

    std::string getName() const { return _name; }
    size_t getAmount() const { return _amount; }
    size_t getBasePrice() const { return _basePrice; }

private:
    std::string _name;
    size_t _amount;
    size_t _basePrice;

    size_t _maxAmount = 255;
};
