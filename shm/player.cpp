#include "player.hpp"

Player::Player(std::shared_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_(ship)
    , money_(money)
    , availableSpace_(availableSpace)
{}

std::shared_ptr<Ship> Player::getShip() const {
    return ship_;
}

size_t Player::getMoney() const {
    return money_;
}

size_t Player::getAvailableSpace() const {
    return availableSpace_;
}

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}

std::vector<std::shared_ptr<Cargo>> Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}
