#include "Fruit.hpp"

size_t Fruit::getPrice() const override{
    return price_;
}
std::string Fruit::getName() const override{
    return name_;
}
size_t Fruit::getAmount() const override{
    return amount_;
}
size_t Fruit::getBasePrice() const override{
    return basePrice_;
}

Fruit& Fruit::operator--(){
    --validityTime_;
    
    return *this;
}

