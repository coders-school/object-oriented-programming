#pragma once 

#include "cargo.hpp"

class Item : public Cargo
{

public:
    enum class Rarity {
        common = 1
        , rare = 5
        , epic = 10
        , legendary = 20
    };

    Item(std::string name, size_t amount, size_t basePrice, Rarity rarity)
        : Cargo(name , amount, basePrice)
        , rarity_(rarity)
        {}
    ~Item();

    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;
    bool operator==(const Cargo& cargo) const override;


    Item& operator--();
    Item& operator--(int);

    size_t getPrice() const override ;
    std::string getName() const override {return name_ ;};
    size_t getAmount() const override {return amount_;};
    size_t getBasePrice() const override {return basePrice_;};
    Rarity getRarity() const {return rarity_;};

private:
    Rarity rarity_;
};

