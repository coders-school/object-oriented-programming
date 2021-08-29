
#pragma once
#include <string>
#include "time.hpp"
#include "iObserver.hpp"

//Class responsible for managing Cargo in the game.
class Cargo : public IObserver {
public:
    Cargo(const std::string& name, size_t amount, size_t basePrice, Time *time);
    Cargo(const std::string& name, size_t amount, size_t basePrice);
    virtual ~Cargo() = default;

    virtual Cargo& operator+=(size_t amount);
    virtual Cargo& operator-=(size_t amount);
    virtual bool operator==(const Cargo&) const;

    virtual size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;

    virtual void setAmount(const size_t& amount) = 0; //{ amount_ = amount; };
    
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;
    Time* time_;
};
