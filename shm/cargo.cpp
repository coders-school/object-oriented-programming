#include <limits>
#include <iostream>
#include "cargo.hpp"

// Cargo &Cargo::operator+=(size_t amount)
// {
//     amount_ += amount;
//     return *this;
// }

// Cargo &Cargo::operator-=(size_t amount)
// {
//     if(amount_ < amount){
//         amount_ = 0;
//     }
//     else{
//         amount_ -= amount;
//     }
//     return *this;
// }


bool Cargo::operator==(const Cargo &cargo) const
{
    return name_ == cargo.name_ && amount_ == cargo.amount_ && basePrice_ == cargo.basePrice_;
}

void Cargo::printCargo() const {
    std::cout << "Cargo Name: " << name_ << ", amount: " << amount_ << '\n';
}

void Cargo::reduceAmount(){
    if(amount_ -1 < 0){
        amount_ = 0;
    }
    else{
        amount_ -= 1;
    }
}

void Cargo::increaseAmount()
{
    amount_ += 1;
}