#ifndef DRYFRUIT_HPP
#define DRYFRUIT_HPP
#include "Fruit.hpp"

// Class used to represent cargo of subtype dry fruit type carried by merchant ship
class DryFruit : public Fruit 
{
private:
    size_t counter_{0};

public:
    using Fruit::Fruit;
    size_t getPrice() const override
    {
        if (timeInCargoRoom_ >= shelfLife_)
            return 0;
        return static_cast<size_t>(
            3 * basePrice_ * ((float)(shelfLife_ - timeInCargoRoom_)) / shelfLife_);
    }
    const std::string &getName() const override { return name_; };

    Fruit &operator++() override
    {
        if (++counter_ == 10)
        {
            ++timeInCargoRoom_;
            counter_ = 0;
        }
        return *this;
    };
};

#endif