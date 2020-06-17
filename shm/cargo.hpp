#pragma once
#include <string>
class Cargo {
public:
    Cargo(std::string name, size_t amount, size_t basePrice);
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(std::string name);
    std::string GetName() const;
    size_t GetAmount() const;
    size_t GetBasePrice() const;



protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};

