#include "Cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity {
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

    Rarity getRarityLevel() const { return rarity_; }

    Cargo& operator+=(const size_t amount) override;
    Cargo& operator-=(const size_t amount) override;
    
    bool operator==(const Cargo& cargo) const override;
    bool operator!=(const Cargo& cargo) const override;

private:
    const Rarity rarity_ = Rarity::common;
};

