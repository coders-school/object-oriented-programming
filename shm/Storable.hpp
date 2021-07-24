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
    Storable(int money, size_t availableSpace)
        : money_(money)
        , availableSpace_(availableSpace)
        {}

    //Constructod for objects subscribed to Time class (i.e. Store)
    Storable(int money, size_t availableSpace, Time* time)
        : money_(money)
        , availableSpace_(availableSpace)
        , time_(time)
        {
            time_->attach(this);
        }

    virtual ~Storable(){}

    int getMoney() {return money_; }
    size_t getAvailableSpace() {return availableSpace_; }
    virtual std::shared_ptr<Cargo> getCargo(size_t index) const = 0;
    void SpendMoney(int moneyToSpend);

protected:
    int money_;
    size_t availableSpace_;
    Time* time_;
};