#include "player.hpp"

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_(std::move(ship)), money_(money), availableSpace_(availableSpace) {}

Cargo* Player::getCargo(size_t index) const {
    if (index < (ship_->getCargo().size())) {
        return ship_->getCargo()[index].get();
    } else {
        return nullptr;
    }
}

void Player::loadShip(std::shared_ptr<Cargo> cargo) {
    ship_->load(cargo);
    countAvailableSpace();
}

void Player::unloadShip(Cargo* cargo) {
    ship_->unload(cargo);
    countAvailableSpace();
}

void Player::countAvailableSpace() {
    size_t amount = 0;
    for (const auto& cargo : ship_->getCargo()) {
        amount += cargo->getAmount();
    }
    
    int available = ship_->getCapacity() - amount;
    if (available < 0) {
        availableSpace_ = 0;
    } else {
        availableSpace_ = available;
    }
}
