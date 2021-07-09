#pragma once

#include <cstddef>
#include <string>

#include "shm/inc/Subscriber.hpp"

constexpr size_t MAX_AMOUNT_OF_CARGO{ 1000 };

//class resposible for manage commodity in game
class Cargo : public Subscriber {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice);
    virtual ~Cargo() = default;

    std::string getName() const { return name_; }
    size_t getAmount() const { return amount_; }
    size_t getBasePrice() const { return basePrice_; }

    void setAmount(size_t amount); 

    virtual Cargo& operator+=(const size_t amount) = 0;
    virtual Cargo& operator-=(const size_t amount) = 0;
    virtual bool operator==(const Cargo& cargo) const = 0;
    virtual size_t getPrice() const = 0;
    virtual bool getIsUsable() const = 0;
    
    // override from Subscriber
    virtual void nextDay() override = 0;

protected:
    const std::string name_; 
    size_t amount_ {};
    size_t basePrice_ {}; 
};
