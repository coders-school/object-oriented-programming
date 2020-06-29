#include "Player.h"

Player(Ship ship, size_t money)
	: ship_(std::make_shared<Ship>(ship), money_(money) {}


size_t Player::getAvailableSpace() const {
    return available_space_;
}

size_t Player::getMoney() const {
    return money_;
}

Ship* Player::getShip() const {
    return ship_->Get()}

size_t Player::getSpeed() const {
    return ship_.getSpeed();
}

Cargo* Player::getCargo(size_t index) const {
    return ship_->getCargo(index).get();
}

void Player::checkAvailableSpace()
{
    size_t usedSpace = std::accumulate(ship_->getCargo().begin(), ship_->getCargo().end(), 0, 
    [](size_t total, auto item) { return total + item->getAmount(); });
    available_space_ = ship->getCapacity() - usedSpace;
}
