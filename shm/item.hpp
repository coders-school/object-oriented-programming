#pragma once
#include<string>
#include "timeSHM.hpp"
class Item : public Cargo, public Observer {
public:

Item(std::string name, size_t amount, size_t basePrice, size_t rarity, Time* Publisher);

    enum class Rarity {
        common = 1,
        rare = 3,
        epic = 8,
        legendary = 50,
    };

    // override from Observer
    void nextDay() override;
    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override; 
    size_t getBasePrice() const override;
private:
    const size_t rarity_;
    Time* Publisher_;
};
