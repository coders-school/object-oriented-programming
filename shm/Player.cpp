#include "Player.hpp"
#include <iostream>


Player::Player(std::unique_ptr<Ship>& ship, int money)
    : ship_(std::move(ship)), money_(money) {
    calculateAvailableSpace();
}

Cargo* Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}

void Player::calculateAvailableSpace() {
    
    size_t capacity = ship_->getCapacity();
    size_t cargoAmount = ship_->calculateCargoAmount();
    
    if (capacity - cargoAmount < 0) {
        availableSpace_ = 0;
    }

    availableSpace_ = capacity - cargoAmount;
}

void Player::printCargo() const {
    if (!ship_) {
        return;
    }
    std::cout << "\n"
              << ship_->getName() << "\n";
    std::cout << "Ship capacity: " << ship_->getCapacity() << "\n"
              << "Available space: " << availableSpace_ << "\n" << "\n"
              << "Goods in the cargo room: " << "\n";
    ship_->printCargolist();
    std::cout << "\n";
}

void Player::PurchaseCargo(std::unique_ptr<Cargo> cargo, size_t price) {
    ship_->load(std::move(cargo));
    money_ -= price;
    calculateAvailableSpace();
}

void Player::SellCargo(Cargo* cargo, size_t price) {
    ship_->unload(cargo);
    money_ += price;
    calculateAvailableSpace();
};