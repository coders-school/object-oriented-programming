#include "player.hpp"

#include <iostream>

// constructors

Player::Player(Ship& ship , size_t money , size_t availableSpace )
    : ship_(std::make_shared<Ship> (ship ))
    , money_(money)
    , availableSpace_(availableSpace) 
    {}

//Player::~Player(){};

//getters

size_t Player::getMoney() const {
    return money_;
}
size_t Player::getAvailableSpace() const {
    return availableSpace_;
}
std::shared_ptr<Ship> Player::getShip() const {
    return ship_;
};

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}
std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    
    return ship_->getCargo(index);
}




//methods



