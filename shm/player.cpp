#include "player.hpp"

#include <memory>

Player::Player(Ship* ship, size_t money)
    : ship_(std::make_unique<Ship>(ship)), money_(money) {}

Player::Player(Ship* ship)
    : Player(ship, DEFAULT_MONEY) {}

size_t Player::GetSpeed() {
    return ship_->GetSpeed();
}

Cargo Player::GetCargo(size_t index) {
    return ship_->GetCargo(index);
}