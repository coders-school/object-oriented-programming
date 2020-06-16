#include "player.hpp"

void Player::setShip(const std::shared_ptr<Ship>& ship) {
    ship_ = ship;
}

void Player::addMoney(const size_t& money) {
    money_ = money;
}

void Player::setAvailableSpace(const size_t& space) {
    size_t availableSpace_ = space;
}