#include "cargo.hpp"

class Item : public Cargo {
public:
    Item(std::string name, size_t amount, double basePrice);
    ~Item() override {}
    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(const size_t& amount) {
        if (amount_ - amount >= 0) {
            amount_ -= amount;
        }
        return *this;
    }
    std::string getName() const override {return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override { return getBasePrice() * static_cast<int>(rarity_); }
    Rarity getRarity() const { return rarity_; }
private:
    Rarity rarity_;
};

