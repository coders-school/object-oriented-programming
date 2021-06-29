#include "Alcohol.hpp"
 
size_t Alcohol::getPrice() const override{
    return price_;
}
std::string Alcohol::getName() const override{
    return name_;
}
size_t Alcohol::getAmount() const override{
    return amount_;
}
size_t Alcohol::getBasePrice() const override{
    return basePrice_;
}

