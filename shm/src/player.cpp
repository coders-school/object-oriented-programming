#include "player.hpp"


constexpr auto shipName = "ship";
constexpr int shipCapacity = 100;
constexpr int shipMaxCrew = 30;
constexpr int shipSpeed = 10;
constexpr size_t shipId = 1;

Player::Player(std::unique_ptr<Ship> ship, size_t money)
    : ship_(std::move(ship)), money_(money), availableSpace_(ship->getCapacity()) {}

Player::Player(size_t money)
: money_(money) {
    ship_ = std::make_unique<Ship>(shipCapacity, shipMaxCrew, shipSpeed, shipName, shipId, this);
    availableSpace_ = ship_->getCapacity();
}

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

void Player::unloadShip(Cargo* cargo, size_t amount) {
  ship_->unload(cargo, amount);
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

void Player::payCrew(size_t money) {
    (money_ < money) ? money_ = 0 : money_ -= money;
}
