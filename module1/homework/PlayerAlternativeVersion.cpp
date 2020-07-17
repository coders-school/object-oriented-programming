#include "PlayerAlternativeVersion.hpp"

Player::Player(std::shared_ptr<Ship> ship, uint16_t money, uint16_t availableSpace)
    : ship_(ship), money_(money), availableSpace_(availableSpace) {}

uint16_t Player::getSpeed() const {
    return ship_->getSpeed();
}
uint16_t Player::getMoney() const {
    return money_;
}
uint16_t Player::getAvailableSpace() const {
    return availableSpace_;
}
Cargo* Player::getCargo(uint16_t index) const {
    return ship_->getCargo(index);
}

void Player::updateAvailableSpace() {
    uint16_t space = ship_->getCapacity();

    for (const auto cargo : ship_->getCargos()) {
        if (space > cargo->getAmount()) {
            space -= cargo->getAmount();
        } else {
            break;
        }
    }
    availableSpace_ = space;
}
