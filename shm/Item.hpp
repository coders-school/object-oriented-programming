#include "Cargo.hpp"

class Item : public Cargo {
public:
    enum class RarityLevel {
        common = 1,
        rare = 2, 
        epic = 5, 
        legendary = 10
    };

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPrice() const override { return basePrice_ * static_cast<int>(rarity_); }

    RarityLevel getRarityLevel() const { return rarity_; }

private:
    const RarityLevel rarity_ = RarityLevel::common;
};
