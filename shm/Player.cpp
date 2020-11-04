#include "Player.hpp"

Player::Player(std::shared_ptr<Ship> ship, uint16_t money, uint16_t availableSpace)
    : ship_(ship), money_(money), availableSpace_(availableSpace) {}

std::shared_ptr<Ship> Player::getShip() const {
    return ship_;
}

uint16_t Player::getMoney() const {
    return money_;
}

uint16_t Player::getAvailableSpace() const {
    return availableSpace_;
}

uint16_t Player::getSpeed() const {
    return ship_->getSpeed();
}

std::shared_ptr<Cargo> Player::getCargo(uint16_t index) const {
    return ship_->getCargo(index);
}

void Player::updateAvailableSpace() {
    uint16_t space = ship_->getCapacity();

    for (const auto& cargo : ship_->getCargos()) {
        if (space > cargo->getAmount()) {
            space -= cargo->getAmount();
        } else {
            availableSpace_ = 0;
            return;
        }
    }

    availableSpace_ = space;
}

void Player::setMoney(uint16_t money) {
    money_ = money;
}

void Player::payCrew(uint16_t money) {
    if (money_ > money) {
        money_ -= money;
        return;
    }
    money_ = 0;
}

void Player::loadCargoOnShip(std::shared_ptr<Cargo> cargo) {
    ship_->load(cargo);
    updateAvailableSpace();
}

void Player::unloadCargoFromShip(std::shared_ptr<Cargo> cargo, uint16_t amount) {
    ship_->unload(cargo, amount);
    updateAvailableSpace();
}