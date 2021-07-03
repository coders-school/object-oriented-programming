#include <numeric>

#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"

Player::Player(std::unique_ptr<Ship> ship, int money, int availableSpace)
    : ship_(std::move(ship))
    , money_(money)
    , availableSpace_(calculateAvailableSpace())
    {}

const std::unique_ptr<Ship>& Player::getShip() { 
    return ship_; 
}

int Player::getMoney() { 
    return money_; 
}

size_t Player::getAvailableSpace () { 
    return availableSpace_; 
}

size_t Player::getSpeed() const {
    if(ship_)
    {
        return ship_->getSpeed(); 
    }
    return 0; // TODO add something better
}

Cargo* Player::getCargo(size_t index) const {
    if(ship_)
    {
        return ship_->getCargo().at(index);
    }
    return nullptr; // TODO add something better
}

size_t Player::calculateAvailableSpace() {
     int cargoAmount = 0;
     int capacity = ship_->getCapacity();
     std::vector<Cargo*> shipCargo = ship_->getCargo();

     //cargoAmount = std::accumulate(shipCargo.begin(), shipCargo.end(), 0, [](int i, Cargo c) { return i += c.getAmount(); }); TODO
    
    for(int i = 0; i < shipCargo.size(); i++){
         cargoAmount += getCargo(i)->getAmount();
    }
    if(capacity - cargoAmount < 0)
    {
        return 0;
    }
    
     return capacity - cargoAmount;
}
