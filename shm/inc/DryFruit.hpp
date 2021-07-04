#pragma once

"shm/inc/Fruit.hpp"

class DryFruit : public Fruit {
public:
    DryFruit(const std::string& name, size_t amount, size_t basePrice);
    
    //override from Fruit
    ~DryFruit() override; 
    DryFruit& operator--() override;

    std::size_t getPrice() const override;
    std::string getName() const override { return name_; }

private:
    size_t rottenDryFruit_ { 10 };
    size_t multiplierDryFruit_ { 3 };
};