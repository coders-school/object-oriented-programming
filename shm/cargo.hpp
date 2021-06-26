#pragma once
#include <string>

class Cargo
{
public:
    Cargo &operator+=(size_t amount);
    Cargo &operator-=(size_t amount);
    bool operator==(const Cargo &cargo) const;

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
