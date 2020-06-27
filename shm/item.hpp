#pragma once
#include<string>

class Item : public Cargo {
public:

Item(std::string name, size_t amount, size_t basePrice, size_t rarity);

    enum class Rarity {
        common = 1,
        rare = 3,
        epic = 8,
        legendary = 50,
    };

    //Override from Cargo
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override; 
    size_t getBasePrice() const override;
private:
    const size_t rarity_;
};
