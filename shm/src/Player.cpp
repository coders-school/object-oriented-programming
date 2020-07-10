#include "Player.hpp"

#include <algorithm>

Player::Player(std::shared_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_(ship), money_(money), availableSpace_(availableSpace) { }

Ship* Player::getShip() const { return ship_.get(); }
size_t Player::getMoney() const { return money_; }
size_t Player::getAvailableSpace() const { return availableSpace_; }
size_t Player::getSpeed() const { return ship_->getSpeed(); }
Cargo* Player::getCargo(size_t index) const { return ship_->getCargo(index); }

size_t Player::calculateAvailableSpace() {
    return (ship_->getCapacity() - ship_->getCargoWeight());
}
