
#include <iostream>
#include <numeric>
#include <utility>

#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"

Player::Player(std::shared_ptr<Ship> ship, const size_t& money)
    : ship_(std::move(ship)), money_(money) {
    countAvailableSpace();
}

size_t Player::getMoney() const {
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

size_t Player::countAvailableSpace() const {
    auto sumOfAmounts = std::accumulate(ship_->getCargos().begin(), ship_->getCargos().end(), 0
        , [](size_t amountAll, const auto& cargo) {return amountAll += cargo.get()->getAmount();});
    
    if(ship_->getCapacity() - sumOfAmounts < 0)
    {
        return 0;
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
        std::cout << i++ << " Name: " << el->getName() << ",\t\t Amount: " << el->getAmount() << ",\t\t Base proce: " << el->getBasePrice() << '\n';
    }
}