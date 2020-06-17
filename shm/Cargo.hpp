#pragma once

#include <string>

class Cargo {
public:
    Cargo& operator+=(const size_t);
    Cargo& operator-=(const size_t);

    std::string getName() const { return _name; }
    size_t getAmount() const { return _amount; }
    size_t getBasePrice() const { return _basePrice; }

private:
    std::string _name;
    size_t _amount;
    size_t _basePrice;
};
