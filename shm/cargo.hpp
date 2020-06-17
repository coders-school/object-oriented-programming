#pragma once
#include <string>
class Cargo {
public:
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(std::string name);



protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
}

