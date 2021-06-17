#include "Player.hpp"
#include "Ship.hpp"
#include "Cargo.hpp"
#include <memory>
#include <utility>
#include <vector>

void Player::calculateAvailableSpace() {
    const std::vector<std::unique_ptr<Cargo>>& cargoVec = ship_->getCargoVec();
    size_t usedSpace {0};
    size_t shipCapacity = ship_->getCapacity();
    for(const auto& cargo : cargoVec) {
        usedSpace += cargo->getAmount();
    }
    if(usedSpace > shipCapacity) {
        availableSpace_ = 0;
    }
    availableSpace_ = shipCapacity - usedSpace;
}

Player::Player(std::unique_ptr<Ship> ship, const size_t& money, const size_t& availableSpace)
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
    return ship_->getSpeed();
}

Cargo* Player::getCargo(size_t index) const {
    Cargo* ptr;
    try {
        ptr = ship_->getCargoVec().at(index).get();
    } catch (...) {
        return nullptr;
    }
    return ptr;
}
