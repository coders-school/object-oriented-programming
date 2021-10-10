#include "cargo.hpp"

#include <iostream>
#include <limits>


Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice, std::shared_ptr<Time> time)
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
    , time_(time)
    {
        if (time_) {
            time_->attachObserver(this);
        }
    }

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice) 
    {};

//Cargo& Cargo::operator+=(size_t amount) {
//    if (amount_ + amount < std::numeric_limits<size_t>::max()) {
//        amount_ += amount;
//    }
//    return *this;
//}
//
//Cargo& Cargo::operator-=(size_t amount) {
//    if (amount_ >= amount ) {
//        amount_ -= amount;
//    }
//    return *this;
//}

//bool Cargo::operator==(const Cargo& cargo) const {
//    return cargo.getName() == getName();
//}
