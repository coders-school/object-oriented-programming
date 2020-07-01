#pragma once
#include<string>
#include "timeSHM.hpp"
#include "cargo.hpp"
#include "Rarity.hpp"
class Item : public Cargo, public Observer {

public:

    // override from Observer
    Item(std::string name, size_t amount, size_t basePrice, int rarity, Time* Publisher);

    ~Item() override = default;
    void nextDay() override;

    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
    int getRarity() const;

private:
    Time* Publisher_;
    int rarity_;
};
