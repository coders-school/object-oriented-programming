#pragma once

#include <string>

class Cargo {
public:
    bool operator==(const Cargo& cargo) const;
    bool operator!=(const Cargo& cargo) const;
    Cargo& operator+=(const size_t amount);
    Cargo& operator-=(const size_t amount);

private:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
