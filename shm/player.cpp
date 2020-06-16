#include "player.hpp"

Player::Player(std::shared_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_{ship}, money_{money}, availableSpace_{availableSpace} {}

void Player::setShip(const std::shared_ptr<Ship>& ship) {
    ship_ = ship;
}

void Player::addMoney(const size_t& money) {
    money_ = money;
}

void Player::setAvailableSpace(const size_t& space) {
    size_t availableSpace_ = space;
}