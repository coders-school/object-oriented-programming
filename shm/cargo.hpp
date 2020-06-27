#pragma once

#include <string>

class Cargo {
public:
    Cargo(uint32_t amount, std::string name, uint32_t basePrice);
    ~Cargo();

    uint32_t getAmount() const;
    uint32_t getBasePrice() const;
    std::string getName() const;

    Cargo& operator+=(uint32_t amount);
    Cargo& operator-=(uint32_t amount);
    bool operator==(Cargo& cargo);

private:
    uint32_t amount_ = {};
    std::string name_ = {};
    uint32_t basePrice_ = {};
};
