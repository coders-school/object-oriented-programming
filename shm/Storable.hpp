#pragma once 
#include <iostream>
#include <memory>
#include "Time.hpp"
#include "TimeEffectable.hpp"


class Cargo;

// Interface for classes storing Cargo objects
class Storable : public TimeEffectable 
{
public:
    // Constructor for objects not subscribed to Time class (i.e. Player)
    Storable(int money, size_t availableSpace);

    //Constructor for objects subscribed to Time class (i.e. Store)
    Storable(int money, size_t availableSpace, Time* time);
    
    virtual ~Storable();

    int getMoney() {return money_; }
    size_t getAvailableSpace() {return availableSpace_; }
    virtual Cargo * getCargo(size_t) const = 0;
    void SpendMoney(int);
    void EarnMoney(int);
    void removeCargo(std::shared_ptr<Cargo>, size_t);

protected:
    int money_;
    size_t availableSpace_;
    Time* time_;
};