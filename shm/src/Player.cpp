#include "../inc/Player.hpp"

Player::Player(Ship& ship, size_t money, size_t availableSpace)
        : ship_(std::make_unique<Ship>(ship)), money_(money), availableSpace_(availableSpace)
    {} 

size_t Player::getSpeed() const {
    return ship_->getSpeed();
};

Cargo* Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}
