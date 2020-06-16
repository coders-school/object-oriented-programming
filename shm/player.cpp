#include "player.hpp"

#include <memory>

Player::Player(Ship* ship, size_t money, size_t space)
    : ship_(std::make_unique<Ship>(ship)), money_(money), availableSpace_(space) {}

Player::Player(Ship* ship)
    : Player(ship, START_MONEY, START_SPACE) {}

size_t Player::GetSpeed() {
    if (ship_)
        return ship_->GetSpeed();

    return 0;
}

Cargo Player::GetCargo(size_t index) {
    if (ship_)
        return ship_->GetCargo(index);

    return 0;
}