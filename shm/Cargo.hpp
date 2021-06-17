#pragma once

#include <string>

class Cargo {
protected:
     std::string name_;
     size_t amount_;
     size_t basePrice_;

public:
    Cargo(std::string name, size_t amount, size_t basePrice);

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo& other) const;

    std::string getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;

};
