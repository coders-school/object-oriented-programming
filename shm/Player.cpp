#include "Player.hpp"

#include <utility>

Player::Player(std::unique_ptr<Ship> ship, size_t money) {
    ship_ = std::move(ship);
    money_ = money;
}

size_t Player::getMoney() const {
    return money_;
}
int Player::getSpeed() const {
    return ship_->getSpeed();
}
Cargo* Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}
