#include "Player.h"

#include <numeric>

Player::Player(Ship ship, size_t money)
    : ship_(std::make_unique<Ship>(ship)), money_(money) {}

size_t Player::getAvailableSpace() const {
    return available_space_;
}

size_t Player::getMoney() const {
    return money_;
}

void Player::setMoney(size_t amount) {
    money_ = amount;
}

Ship* Player::getShip() const {
    return ship_.get();
}

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}

Cargo* Player::getCargo(size_t index) const {
    if (ship_) {
        return ship_->getCargo(index).get();
    }

    return nullptr;
}

void Player::checkAvailableSpace() {
    size_t usedSpace = std::accumulate(ship_->getCargos().begin(), ship_->getCargos().end(), 0,
                                       [](size_t total, auto item) { return total + item->getAmount(); });
    available_space_ = ship_->getCapacity() - usedSpace;
}

std::vector<std::shared_ptr<Cargo>> Player::getCargos() const {
    return ship_->getCargos();
}
