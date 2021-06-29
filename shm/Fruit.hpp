#pragma once 

#include "Cargo.hpp"

class Fruit : public Cargo {
public: 
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;

    Fruit& operator--();

private:
    size_t validityTime_; 

};
