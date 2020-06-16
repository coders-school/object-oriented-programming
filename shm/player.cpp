#include "player.hpp"

#include <memory>

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t space)
    : ship_(std::move(ship)), money_(money), availableSpace_(space) {}

Player::Player(std::unique_ptr<Ship> ship)
    : Player(std::move(ship), START_MONEY, START_SPACE) {}

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
