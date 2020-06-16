#pragma once

#include <string>

class Cargo {
public:
    Cargo& operator+=(size_t);
    Cargo& operator-=(size_t);
    bool operator==(const Cargo&);

protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
