#pragma once
#include <string>
#include "timeSHM.hpp"
#include "cargo.hpp"
#include <iostream>

class Fruit : public Cargo, public Observer {
public:    
    Fruit(std::string name, size_t amount, size_t basePrice, size_t expiryDate, size_t timeElapsed, Time* Publisher);

    ~Fruit(){
        this->Publisher_->removeObserver(this);
        std::cout<<"Goodbye! I was your Fruit"<<'\n';
    };

    void nextDay() override;

    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    Fruit& operator--();
    size_t getExpiryDate() const;
    size_t getTimeElapsed() const;
    size_t timeToRot() const;
private:
    Time* Publisher_;
    size_t timeElapsed_{0};    
    const size_t expiryDate_{12};
    size_t timeToSpoil_ = expiryDate_ - timeElapsed_;
};
