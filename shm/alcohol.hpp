#pragma once

#include <iostream>
#include <string>

#include "cargo.hpp"
#include "timeSHM.hpp"


class Alcohol : public Cargo, public Observer {
public:
    Alcohol(std::string name, size_t amount, size_t basePrice, size_t power, Time* Publisher);
    
    ~Alcohol(){
        this->Publisher_->removeObserver(this);
        std::cout << "Goodbye, I was your Alcohol :)\n";
    };

//Override from Observer
    void nextDay() override;

//Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    size_t getPower() const;

private:
    size_t power_;
    Time* Publisher_;
};
