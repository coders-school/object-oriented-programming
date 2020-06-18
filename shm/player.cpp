#include "player.hpp"

#include <numeric>

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_(std::move(ship)), money_(money), availableSpace_(availableSpace) {}

std::unique_ptr<Ship> Player::getShip() {
    return std::move(ship_);
}
size_t Player::getAvailableSpace() const {
    return availableSpace_;
}
size_t Player::getMoney() const {
    return money_;
}

size_t Player::CountAvailableSpace() const {
    size_t sumOfAmounts =
        std::accumulate(ship_->getVectorCargo().begin(), ship_->getVectorCargo().end(), 0,
                        [](size_t amounts, const Cargo& cargo) { return amounts += cargo.getAmount(); });

    return ship_->getCapacity() - sumOfAmounts;
}

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}
Cargo* Player::getCargo(size_t index) const {
    if (ship_)
        return &ship_->getCargo(index);
    return nullptr;
}
