#include "cargo.hpp"

enum class Rarity { common = 1,
                    rare = 3,
                    epic = 6,
                    legendary = 10 };

class Item : public Cargo {
public:
    Item(std::string name, size_t amount, double basePrice);
    ~Item() override {}

    Rarity getRarity() const { return rarity_; }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override { return getBasePrice() * static_cast<int>(rarity_); }
    

    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(const size_t& amount) {
        if (amount_ >= amount) {
            amount_ -= amount;
        }
        return *this;
    }

    bool operator==(Cargo& item) const override {
        return getName() == item.getName() &&
               getPrice() == item.getPrice() &&
               getBasePrice() == item.getBasePrice();
    }

private:
    Rarity rarity_;
};
