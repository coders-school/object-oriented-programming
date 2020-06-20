
#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(std::string name, size_t amount, double basePrice);
    ~Fruit() override {}

    Cargo& operator--() {
        if (timeToRotten_ > 0) {
            timeToRotten_--;
        }
        return *this;
    }
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
    size_t getTimeToRotten() const { return timeToRotten_; }
    double getPrice() const override {
        return basePrice_ * (1 / std::exp(timeToRotten_));}
    size_t getExpiryDate() const { return timeToRotten_; }

protected:
    size_t time_elapsed_{0};
    size_t timeToRotten_;
};

class DryFruit : public Fruit {
    std::string getName() const override { return "Dry Fruit"; }
    double getPrice() const override {
        return 3 * basePrice_ * (1 / std::exp(timeToRotten_));}
    Cargo& operator--() override {
        if (++counter_ == 10) {
            ++time_elapsed_;
            counter_ = 0;
        }
        return *this;
    }
private:
    size_t counter_{0};
};