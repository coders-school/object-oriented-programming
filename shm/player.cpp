#include "player.hpp"

Player::Player(std::unique_ptr<Ship>& ship, int money, int availableSpace)
    : ship_(std::move(ship))
    , money_(money)
    , availableSpace_(availableSpace)
    {}

std::unique_ptr<Ship>& Player::getShip() { 
    return ship_; 
}

int Player::getMoney() { 
    return money_; 
}

size_t Player::getAvailableSpace () { 
    return availableSpace_; 
}

size_t Player::getSpeed() const { 
    return ship_->getSpeed(); 
}

Cargo* Player::getCargo(size_t index) const {
    return ship_->getCargo()[index];
}

void Player::calculateAvailableSpace() {
    // size_t cargoAmount = 0;
    // std::vector<Cargo*> shipCargo = ship_.;
    // for(int i = 0; i < shipCargo.size(); i++){
    //     cargoAmount += getCargo(i)->getAmount();
    // }

    // availableSpace_ = ship_.getCapacity() - cargoAmount;
}