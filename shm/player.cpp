#include "player.hpp"
#include <memory>
#include <utility>

void Player::calculateAvailableSpace() {
    // Implementation will be based on cargo aggregation in ship class - for now does nothing
}

Player::Player(std::unique_ptr<Ship>& ship, const size_t& money, const size_t availableSpace)
    : ship_{std::move(ship)}, money_{money}, availableSpace_{availableSpace} {}

const std::unique_ptr<Ship>& Player::getShip() const {
    return ship_;
}

size_t Player::getMoney() const {
    return money_;
}

size_t Player::getAvailableSpace() const {
    return availableSpace_;
}

size_t Player::getSpeed() const {
    // return ship_->getSpeed(); Uncomment after implementation of Ship.getSpeed()
    return 0;  // Placeholder
}

Cargo* Player::getCargo(size_t index) const {
    // Implementation will be based on cargo aggregation in ship class
    return nullptr;  // Placeholder
}
