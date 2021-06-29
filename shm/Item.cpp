#include "Item.hpp"
 
size_t Item::getPrice() const override{
    return price_;
}
std::string Item::getName() const override{
    return name_;
}
size_t Item::getAmount() const override{
    return amount_;
}
size_t Item::getBasePrice() const override{
    return basePrice_;
}

