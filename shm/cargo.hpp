#pragma once
#include <string>
#include "time.hpp"
#include "iObserver.hpp"

//Class responsible for managing Cargo in the game.
class Cargo : public IObserver {
public:
    Cargo(std::string name, size_t amount, size_t basePrice, Time *time);

    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);
    bool operator==(const Cargo&) const;

    const std::string& getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;
    
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
    Time* time_;
};
