#pragma once

#include <string>

class Cargo {
public:
    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;

    Cargo(std::string name, size_t amount, size_t basePrice);
    
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo& cargo) const; 
    
    std::string getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;

private:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
