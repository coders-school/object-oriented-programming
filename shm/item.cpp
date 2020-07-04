#include "item.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctype.h>

Item::Item(std::string name, size_t amount, size_t basePrice,  int rarity, Time* Publisher):
    Cargo(name, amount, basePrice),
    rarity_(rarity),
    Publisher_(Publisher){
    this->Publisher_->addObserver(this);
    }

//Override from Observer
void Item::nextDay(){
    int lottery = rand()%100+1; 
    switch(lottery){
    case 1: 
        std::cout<<"One of your item has been stolen by crew\n";
        --amount_;
        break;
    case 20:
        std::cout<<"One of your item has drowned, I am sorry!\n";
        --amount_;
        break;
    case 60:
        std::cout<<"Your item has been partially damaged by mice\n";
        basePrice_ = static_cast<size_t>(static_cast<double>(basePrice_) * 0.9);
        break;
    case 90:
        std::cout<<"Your item corroded\n";
        basePrice_ = static_cast<size_t>(static_cast<double>(basePrice_)*0.5);
        break;
    default: 
        std::cout << "Fortunately nothing has changed!\n" << '\n';
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

int Item::getRarity() const {
    return rarity_;
}
