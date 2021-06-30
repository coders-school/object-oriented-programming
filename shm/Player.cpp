#include "Player.hpp"
#include "Ship.hpp"
#include "Cargo.hpp"
#include <memory>
#include <utility>
#include <vector>
#include <iostream>

void Player::calculateAvailableSpace() {
    const auto& cargoVec = ship_->getCargoVec();
    if(ship_->getCapacity() <= cargoVec.size()) {
        availableSpace_ = 0;
    }
    availableSpace_ = ship_->getCapacity() - cargoVec.size();
}

Player::Player(std::unique_ptr<Ship> ship, const size_t& money)
    : ship_{std::move(ship)}, money_{money} {
        calculateAvailableSpace();
    }

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
    if(ship_) {
        return ship_->getSpeed();
    }
    return 0;
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

void Player::printCargoManifest() const {
    const auto& cargoVec = ship_->getCargoVec();
    std::cout << "Ship capacity: " << ship_->getCapacity() << '\n'
              << "Cargo on board: " << ship_->getCargoVec().size() << '\n'
              << "Available space: " << availableSpace_ << '\n';
    size_t i {1};
    for(const auto& cargoUnit : cargoVec) {
        std::cout << i++ << ". Name: " << cargoUnit->getName()
                  << ", Amount: " << cargoUnit->getAmount()
                  << ", Base price: " << cargoUnit->getBasePrice()
                  << '\n';
    }

}
