#pragma once

#include <string>

class Cargo {
public:
    Cargo(std::string name, size_t amount, size_t basePrice);

    Cargo& operator+=(const size_t& amount);
    Cargo& operator-=(const size_t& amount);
    bool operator==(const Cargo& cargo) const;
    
    std::string getName() const;

private:
    size_t amount_;
    size_t basePrice_;
    std::string name_;
};
