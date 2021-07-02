
#include <iostream>
#include <numeric>
#include <utility>

#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"

// constructors

Player::Player(std::shared_ptr<Ship> ship, size_t money)
    : ship_(std::move(ship)), money_(money) {
    countAvailableSpace();
}

size_t Player::getMoney() const {
    return money_;
}
size_t Player::getAvailableSpace() const {
    return availableSpace_;
}
std::shared_ptr<Ship> Player::getShip() const {
    return ship_;
};

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}
std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}

void Player::countAvailableSpace() {
    const auto& cargoVector = ship_->getCargosVector();
    if (ship_->getCapacity() <= cargoVector.size()) {
        availableSpace_ = 0;
    }
    availableSpace_ = ship_->getCapacity() - cargoVector.size();
}

//methods
