#ifndef ITEM_HPP
#define ITEM_HPP
#include "Cargo.hpp"
#include "Rarity.hpp"

// Class used to represent cargo of Item type carried by merchant ship
class Item : public Cargo{

private:
    Rarity rarity_;

public:
    Item(const std::string& name, size_t amount,  size_t basePrice , Rarity rarity );
    ~Item() override = default;

    size_t getPrice() const override {return basePrice_ * static_cast<int>(rarity_);};
    const std::string& getName() const override {return name_;}
    size_t getAmount() const override {return amount_;};
    size_t getBasePrice() const override {return basePrice_;};

    Rarity getRarity() const { return rarity_; }
};


#endif