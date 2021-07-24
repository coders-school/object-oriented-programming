#include <limits>
#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice, Time *time) 
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
    , time_(time)
    {
        time->attach(this);
    }

Cargo &Cargo::operator+=(size_t amount)
{
    amount_ += amount;
    return *this;
}

Cargo &Cargo::operator-=(size_t amount)
{
    if(amount_ < amount){
        amount_ = 0;
    }
    else{
        amount_ -= amount;
    }
    return *this;
}

bool Cargo::operator==(const Cargo &cargo) const
{
    return name_ == cargo.name_ && amount_ == cargo.amount_ && basePrice_ == cargo.basePrice_;
}

void Cargo::printCargo() const {
    std::cout << "Cargo Name: " << name_ << ", amount: " << amount_ << ", price: " << getPrice() <<'\n';
}

std::string Cargo::getCargoInfo(){
    return "Cargo Name: " + name_ + ", amount: " + std::to_string(amount_) + ", price: " + std::to_string(getPrice()) +'\n';
}

void Cargo::reduceAmount(){
    if(amount_ -1 < 0){
        amount_ = 0;
    }
    else{
        amount_ -= 1;
    }
}