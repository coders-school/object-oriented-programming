#include "cargo.hpp"

enum class Rarity { common = 1,
                    rare = 3,
                    epic = 6,
                    legendary = 10 };

class Item : public Cargo {
public:
    Item(std::string name, size_t amount, double basePrice);
    Item(std::string name, size_t amount, double basePrice, Rarity rarity);
    ~Item() override {}

    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override { return price_; }
    void nextDay() {}
    size_t getTimeToRotten() const {}
    Rarity getRarity() const { return rarity_; }
    double setPrice() const;

    Cargo& operator+=(const size_t& amount) override {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(const size_t& amount) override {
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
    double price_;
};
