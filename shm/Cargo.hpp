#pragma once

#include <string>

class Cargo {
public:
    Cargo& operator+=(const size_t amount);
    Cargo& operator-=(const size_t amount);

    bool operator==(const Cargo& src) const;
    bool operator!=(const Cargo& src) const;

private:
    std::string _name;
    size_t _amount;
    size_t _basePrice;
};
