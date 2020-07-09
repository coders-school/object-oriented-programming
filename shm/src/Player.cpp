#include "../inc/Player.hpp"

#include <algorithm>
#include <memory>

Ship* Player::getShip() const { return ship_.get(); }
size_t Player::getMoney() const { return money_; }
size_t Player::getAvailableSpace() const { return availableSpace_; }
size_t Player::getSpeed() const { return ship_->getSpeed(); }
Cargo* Player::getCargo(size_t index) const { return ship_->getCargo(index); }

Player::Player(std::shared_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_(ship), money_(money), availableSpace_(availableSpace) { }

size_t Player::calculateAvailableSpace() {
    return (ship_->getCapacity() - ship_->getCargoWeight());
}
