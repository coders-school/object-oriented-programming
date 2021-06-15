#pragma once

#include <string>
class Cargo {
public:

    Cargo& operator+=(const uint16_t);
    Cargo& operator-=(const uint16_t);

private:
    const std::string name_ { }; 
    uint16_t amount_ { 0 };
    uint16_t basePrice_ { 0 }; 
};