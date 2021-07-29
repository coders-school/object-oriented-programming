#pragma once
#include <string>

//Class responsible for managing Cargo in the game.
class Cargo {
public:
    Cargo(std::string name, size_t amount, size_t basePrice);

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo&) const;

    const std::string& getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;
    void nextDay();
    
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
    double lifespan_ = 1;
};
