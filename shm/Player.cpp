#include "Player.hpp"

size_t Player::getSpeed() const {
    return this->_ship->getSpeed();
}

Cargo* Player::getCargo(size_t index) const {
    return this->_ship->getCargo(index);
}