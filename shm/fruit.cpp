#include "fruit.hpp"


/// operators
Cargo& Fruit::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
}

Fruit& Fruit::operator--() {
   
    return *this;
}

Fruit& Fruit::operator--(int) {
    
    Fruit& temp(*this);
    if(data_ > 0){
        operator--();
    }

    return *this;
}

bool Fruit::operator==(const Cargo& fruit) const 
{
    // i don't know, what to write here!!!????
}

/// getters
size_t Fruit::getAmount() const  {
    return amount_;
}

size_t Fruit::getBasePrice() const  {
    return basePrice_;
}
std::string Fruit::getName() const  {
    return name_;
}

size_t Fruit::getExpitingTime() const {
    return expiringTime_;
}

size_t Fruit::getData() const {
    return data_;
}

size_t Fruit::getPrice() const  {
    if(data_ - expiringTime_ < 0) {
        return 0;
    }
    return basePrice_ * static_cast<size_t>((static_cast<float>(data_) - static_cast<float>(expiringTime_)/ static_cast<float>(data_))); 
}

