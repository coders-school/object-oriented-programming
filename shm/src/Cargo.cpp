#include "../inc/Cargo.hpp"

Cargo& Cargo::operator+=(const size_t value){
    amount_ += value;
    return *this;
}

Cargo& Cargo::operator-=(const size_t value){
    amount_ -= value;
    return *this;
}

bool operator==(const Cargo& cargo){
    //if(name_ == cargo.)
}