#include "player.hpp"

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t space)
    : ship_(std::move(ship)), money_(money), availableSpace_(space) {}

Player::Player(std::unique_ptr<Ship> ship)
    : Player(std::move(ship), START_MONEY, START_SPACE) {}

size_t Player::getSpeed() const{
    if (ship_) {
        return ship_->getSpeed();
    }
    return 0;
}

Cargo* Player::getCargo(size_t cargo) const{
    if (ship_) {
        return ship_->getCargo(cargo);
    }
    return nullptr;
}

size_t Player::countFreeSpace() {
    availableSpace_ = ship_->getCapacity();
    for (const auto cargo : ship_->getAllCargo()) {
        availableSpace_ -= cargo->getAmount();
    }
    return availableSpace_;
}
