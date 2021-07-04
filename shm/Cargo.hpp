#pragma once

#include <string>

class Cargo {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice);

    Cargo& operator+=(size_t amount);
    //operator-= throws std::invalid_argument. if you will use operator remember about try-catch.
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo& other) const;

    const std::string& getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;

private:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
};
