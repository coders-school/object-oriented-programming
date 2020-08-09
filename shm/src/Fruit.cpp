#include "Fruit.hpp"

std::string Fruit::GetName() const {
      return name_;
}
uint16_t Fruit::getAmount() const {
   return amount_; 
}
uint16_t Fruit::GetPrice() const {
return (1- static_cast< float >(time_elapsed_)/ static_cast< float >(time_to_spoil))*getBasePrice();
}
Cargo& Fruit::operator+=(uint16_t amount){
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(uint16_t amount){

if (amount >= amount_) 
        amount_ = 0;
else  amount_ -= amount;

return *this;
}
Cargo& Fruit::operator--(){

}
bool Fruit::operator==(const Cargo&item) const{
    if (typeid(item) != typeid(Fruit&)) 
        return false;
    
     auto fruit = static_cast<const Fruit*>(&item);
    return name_ == fruit->GetName() &&
           amount_ == fruit->getAmount() &&
           basePrice_ == fruit->getBasePrice() &&
           time_elapsed_ == fruit->GetTimeElapsed() &&
           time_to_spoil == fruit->GetExpiryDate();
}