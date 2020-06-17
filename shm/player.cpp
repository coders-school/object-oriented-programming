#include "player.hpp"

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace)
 : ship_(std::move(ship)), money_(money), availableSpace_(availableSpace){}

//size_t Player::getShip() const { return ship_; }

size_t Player::getAvailableSpace() const { return availableSpace_; }
size_t Player::getMoney() const { return money_; }

size_t Player::CountAvailableSpace(Ship ship) const {
    size_t shipSpace = ship.getCapacity(); 
    size_t wares = 0;

    for(auto ware : ship.items_){
    wares += ware.getAmount();
    }
    
    return shipSpace - wares;
}


size_t Player::getSpeed(Ship ship) const{
    return ship.getSpeed();
}
Cargo* Player::getCargo(Ship ship, size_t index) const{
    Cargo * ware = &ship.items_[index];
    return ware;     
}
