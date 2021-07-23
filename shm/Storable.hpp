#pragma once 
#include <iostream>
#include <memory>

class Cargo;

class Storable {
public:
    Storable(int money, size_t availableSpace)
        : money_(money)
        , availableSpace_(availableSpace)
        {}
    virtual ~Storable();
    int getMoney() {return money_; }
    size_t getAvailableSpace() {return availableSpace_; }
    virtual std::shared_ptr<Cargo> getCargo(size_t index) const = 0;
    void SpendMoney(int moneyToSpend);
    void EarnMoney(int moneyToEarn);

protected:
    int money_;
    size_t availableSpace_;
};