#pragma once

#include <string>

class Cargo {
protected:
     std::string name_;
     size_t amount_;
     size_t basePrice_;

public:
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
};
