#pragma once
#include <string>

class Cargo {
public:
    Cargo& operator+=(const size_t);
    Cargo& operator-=(const size_t);

private:
    const std::string name_ { }; 
    size_t amount_ { 0 };
    size_t basePrice_ { 0 }; 
};
