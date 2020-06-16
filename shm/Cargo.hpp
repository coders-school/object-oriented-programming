#pragma once

#include <string>

class Cargo {
public:
    Cargo& operator+=(const size_t);
    Cargo& operator-=(const size_t);

private:
    std::string _name;
    size_t _amount;
    size_t _basePrice;
};
