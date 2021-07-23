#include "Player.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include "Cargos/Cargo.hpp"
#include "Ship.hpp"

Player::Player(std::unique_ptr<Ship> ship, const size_t& money)
    : ship_{std::move(ship)}, money_{money} {
    calculateAvailableSpace();
}

Ship* Player::getShip() const {
    return ship_.get();
}

const Cargo* Player::getCargo(size_t index) const {
    if (!ship_) {
        return nullptr;
    }
    const auto& cargoVec = ship_->getCargoVec();
    if (cargoVec.size() <= index) {
        return nullptr;
    }
    return cargoVec[index].get();
}

void Player::printCargoManifest() const {
    if (!ship_) {
        return;
    }
    const auto& cargoVec = ship_->getCargoVec();
    std::cout << "Ship capacity: " << ship_->getCapacity() << '\n'
              << "Cargo on board: " << cargoVec.size() << '\n'
              << "Available space: " << availableSpace_ << '\n';
    size_t i{1};
    for (const auto& cargoUnit : cargoVec) {
        std::cout << i++ << ". Name: " << cargoUnit->getName()
                  << ", Amount: " << cargoUnit->getAmount()
                  << ", Base price: " << cargoUnit->getBasePrice()
                  << '\n';
    }
}

size_t Player::getMoney() const {
    return money_;
}

size_t Player::getAvailableSpace() {
    calculateAvailableSpace();
    return availableSpace_;
}

size_t Player::getSpeed() const {
    if (ship_) {
        return ship_->getSpeed();
    }
    return 0;
}

bool Player::pay(size_t money) {
    if (money > money_) {
        return false;
    }
    money_ -= money;
    return true;
}

void Player::income(size_t money) {
    money_ += money;
}

void Player::calculateAvailableSpace() {
    if (!ship_) {
        availableSpace_ = 0;
        return;
    }
    const auto& shipCapacity = ship_->getCapacity();
    const auto& currentCargoSize = ship_->getCargoVec().size();
    if (shipCapacity.value <= currentCargoSize) {
        availableSpace_ = 0;
    }
    availableSpace_ = shipCapacity.value - currentCargoSize;
}
