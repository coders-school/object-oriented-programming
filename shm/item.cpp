#include "item.hpp"
#include "timeSHM.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctype.h>

Item::Item(std::string name, size_t amount, size_t basePrice,  Rarity rarity, Time* Publisher):
    Cargo(name, amount, basePrice),
    rarity_(rarity),
    Publisher_(Publisher){
    this->Publisher_->addObserver(this);
    }

void Item::nextDay(){
    int lottery = rand()%100+1; 
    switch(lottery){
    case 1: 
        std::cout<<"One of your item has been stolen by crew";
        --amount_;
        break;
    case 20:
        std::cout<<"One of your item has drowned, I am sorry!";
        --amount_;
        break;
    case 60:
        std::cout<<"Your item has been partially damaged by mice";
        basePrice_ = static_cast<size_t>(static_cast<double>(basePrice_) * 0.9);
        break;
    case 90:
        std::cout<<"Your item corroded";
        basePrice_ = static_cast<size_t>(static_cast<double>(basePrice_)*0.5);
        break;
    }
}

//Override from Cargo

size_t Item::getPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}
std::string Item::getName() const {
    return name_;
}
size_t Item::getAmount() const {
    return amount_;
}
size_t Item::getBasePrice() const {
    return basePrice_;
}

Item::Rarity Item::getRarity() const {
    return rarity_;
}
