#include "player.hpp"

Player::Player(Ship& ship, size_t money, size_t availableSpace)
    : money_(money), availableSpace_(availableSpace) {
    ship_ = std::make_unique<Ship>(ship);
}

Cargo* Player::getCargo(const std::string& name) const {
    return ship_->getCargo(name);
}

void Player::printShipCargo() {
    ship_->printCargo();
}
