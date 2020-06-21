#pragma once

#include <string>

class Cargo {
public:
    Cargo();
    Cargo(const std::string& name, size_t amount, size_t basePrice);

    bool operator==(Cargo& cargo);
    bool operator!=(Cargo& cargo);
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

    std::string getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;
 
    void setName(std::string name);
    void setAmount(size_t amount);
    void setBasePrice(size_t basePrice);

private:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
