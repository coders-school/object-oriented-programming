#pragma once

#include <string>

class Cargo {
private:
    std::string name_;
    size_t amount_;
    size_t basePrice_;

public:
    Cargo(std::string name, size_t amount, size_t basePrice);

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo& other) const;

    virtual size_t setPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;

};
