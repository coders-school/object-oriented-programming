#include <iostream>
#include <memory>
#include "player.hpp"
#include "cargo.hpp"
#include "ship.hpp"

Player::Player(std::shared_ptr<Ship> ship, size_t money)
    : ship_(ship), money_(money) {}


size_t Player::getMoney() const {
    return money_;
}

size_t Player::calculateAvSpace() {
    auto capacity = ship_->getCapacity();
    auto cargoAmount = ship_->getAmountOfCargosCapacity();
    if (capacity <= cargoAmount) { 
        return capacity; 
    }
    return capacity - cargoAmount;
}

size_t Player::getAvailableSpace() {
    return availableSpace_ = calculateAvSpace();
}

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}


//don't get it what index should be returned 
std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    std::shared_ptr<Cargo> cargoPtr;
    cargoPtr = ship_->getCargo().at(index);
    if (cargoPtr) {
        return cargoPtr;
    }
    return nullptr;
}
