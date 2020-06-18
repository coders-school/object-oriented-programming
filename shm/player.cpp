#include "player.hpp"

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_(std::move(ship)), money_(money), availableSpace_(availableSpace) {}

Cargo* Player::getCargo(size_t index) const {
    if (index < (ship_->getCargo().size())) {
        return &ship_->getCargo()[index];
    } else {
        return nullptr;
    }
}
