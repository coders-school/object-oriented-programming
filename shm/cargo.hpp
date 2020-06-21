#pragma once

#include <string>

class Cargo {
public:
    Cargo(uint32_t amount, std::string name, uint32_t basePrice) {}
    ~Cargo() {}
    Cargo& operator+=(uint32_t amount);
    Cargo& operator-=(uint32_t amount);

    std::string getName();
    uint32_t getAmount();
    uint32_t getBasePrice();
    bool operator==(Cargo& cargo);

private:
    std::string name_;
    uint32_t amount_;
    uint32_t basePrice_;
};
