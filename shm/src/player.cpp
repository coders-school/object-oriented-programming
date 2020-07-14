#include "player.hpp"

#include <iostream>

Player::Player(Ship& ship, size_t money, size_t availableSpace)
    : ship_(std::make_shared<Ship>(ship)), money_(money), availableSpace_(availableSpace) {}

void Player::changeMoney(size_t amount) {
    if (amount < (-1) * money_) {
        std::cerr << "Can't subtract more money than player has (" << amount << " from " << money_ << ')';
        return;
    }
    money_ += amount;
}

void Player::payCrew(size_t money) {
    if (money > money_) {
        std::cerr << "You don't have enough money to pay!!!\n";
        return;
    }
    money_ -= money;
}

void Player::receiveCargo(Cargo* cargo, size_t amount, CargoHolder* cargoHolder) {
    ship_->receiveCargo(cargo, amount, cargoHolder);
}
void Player::clearEmptyCargos() {
    ship_->clearEmptyCargos();
}
