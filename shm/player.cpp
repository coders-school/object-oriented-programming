#include <iostream>
#include <numeric>
#include <utility>
#include "player.hpp"
#include "cargo.hpp"
#include "ship.hpp"

Player::Player(std::shared_ptr<Ship> ship, const size_t& money)
    : ship_(std::move(ship)), money_(money) {
    countAvailableSpace();
}

size_t Player::getMoney() const{
    return money_;
}
size_t Player::getAvailableSpace() const {
    return availableSpace_;
}
std::shared_ptr<Ship> Player::getShip() const {
    return ship_;
}

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}
std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}

void Player::countAvailableSpace() {
    if(!ship_) {
        return;
    }
    const auto& cargoVector = ship_->getCapacity();
    size_t sum = 0;
    for (int i = 0; i < ship_->getCargosVector().size(); i++) {
        sum += ship_->getCargo(i)->getAmount();
    }
    availableSpace_ = cargoVector - sum;
}


void Player::printCargo() const {
    if (!ship_) {
        return;
    }

    std::cout << "Ship name: " << ship_->getName() << '\n'
              << "Ship capacity: " << ship_->getCapacity() << '\n'
              << "Available space: " << availableSpace_ << '\n'
              << '\n';
    int i = 0;
    std::cout << "Current ship's cargo\n";
    for (const auto& el : ship_->getCargosVector()) {
        std::cout << i++ << " Name: " << el->getName() << ",\t\t Amount: " << el->getAmount() << ",\t\t Base price: " << el->getBasePrice() << '\n';
    }
}

void Player::setMoney(size_t money) {
    money_ = money;
}