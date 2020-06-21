#include "cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, double basePrice);
    Alcohol(std::string name, size_t amount, double basePrice, double volume);
    ~Alcohol() override {}

    double getVolume() const { return volume_; }
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override {return price_; }
    double setPrice() const;

    Alcohol& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }

    Alcohol& operator-=(const size_t& amount) {
        if (amount_ >= amount) {
            amount_ -= amount;
        }
        return *this;
    }

    bool operator==(Cargo& alcohol) const override {
        return getName() == alcohol.getName() &&
               getBasePrice() == alcohol.getBasePrice() &&
               getPrice() == alcohol.getPrice();
    }

private:
    double volume_ = 0.96;
    double price_;
};
