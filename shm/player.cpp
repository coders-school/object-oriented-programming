#include "player.hpp"

#include <numeric>

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

Cargo* Player::getCargo(size_t index) const{
    if (ship_) {
        return ship_->getCargo(index);
    }
    return nullptr;
}

size_t Player::countFreeSpace() {
    if (ship_) {
        size_t loadedSpace = std::accumulate(ship_->getAllCargo.begin(), ship_->getAllCargo.end(), 0);
        return ship_->getCapacity() - loadedSpace;
    }
    return 0;
}
