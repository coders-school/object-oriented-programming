#ifndef FRUIT_HPP
#define FRUIT_HPP
#include "Cargo.hpp"

// Class used to represent cargo of fruit type carried by merchant ship
class Fruit : public Cargo {
private:
    size_t shelfLife_;
    size_t timeInCargoRoom_{0};

public:
    Fruit(const std::string& name, size_t amount, size_t basePrice, size_t shelfLife);
    ~Fruit() override = default;

    size_t getPrice() const override {
        if (timeInCargoRoom_ >= shelfLife_ )
            return 0;
        return static_cast<size_t>(
            basePrice_ * ((float)(shelfLife_ - timeInCargoRoom_)) / shelfLife_);
    }
    const std::string& getName() const override { return name_; }
    size_t getAmount() const override { return amount_; };
    size_t getBasePrice() const override { return basePrice_; };
    size_t getShelfLife() const { return shelfLife_; }
    size_t gettimeInCargoRoom() const { return timeInCargoRoom_; }
    Fruit& operator++();

};

#endif