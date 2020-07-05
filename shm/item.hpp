#pragma once

#include <iostream>
#include <string>

#include "cargo.hpp"
#include "timeSHM.hpp"
#include "rarity.hpp"

class Item : public Cargo, public Observer {

public:

    Item(std::string name, size_t amount, size_t basePrice, int rarity, Time* Publisher);

    ~Item(){
        this->Publisher_->removeObserver(this);
    };

// Override from Observer
    void nextDay() override;

//Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    int getRarity() const;

private:
    int rarity_;
    Time* Publisher_;
};
