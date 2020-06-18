#include "player.hpp"

Player::Player(std::shared_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_{ship}, money_{money}, availableSpace_{availableSpace} {}

void Player::setShip(const std::shared_ptr<Ship>& ship) {
    ship_ = ship;
}

void Player::addMoney(const size_t& money) {
    money_ = money;
}

size_t Player::countSpace() {
    size_t totalAmount = std::accumulate(ship_->getCargo().begin(), ship_->getCargo().end(), 0,
                                         [](const Cargo& item1, const Cargo& item2) {
                                             return item1.getAmmount() + item2.getAmmount();
                                         });

    return ship_->getCapacity() - totalAmount;
}