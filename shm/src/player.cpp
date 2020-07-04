#include "player.hpp"

#include <numeric>

Player::Player(std::shared_ptr<Ship> ship, size_t money)
    : ship_{ship}, money_{money}, availableSpace_{getAvailableSpace()} {}
Player::Player(size_t money)
    :money_(money) {
    ship_ = Player::generateShip();
}


std::shared_ptr<Ship> Player::generateShip() {
    return std::make_shared<Ship>(1, "Maria", 1, 128, 1200, this);
}
void Player::setShip(const std::shared_ptr<Ship>& ship) {
    ship_ = ship;
}

void Player::addMoney(const size_t& money) {
    money_ += money;
}

void Player::subtractMoney(const size_t& money) {
    money_ -= money;
}

void Player::payCrew(size_t money) {
    Player::subtractMoney(money);
}

size_t Player::getAvailableSpace() const {
   size_t totalAmount = 0;
   for(const auto el : ship_->getCargo()){
       totalAmount += el->getAmount();
   }
    return ship_->getCapacity() - totalAmount;
}

void Player::printCargo() const {
    ship_ -> printCargo();
}

void Player::nextDay() {
    ship_->nextDay();
}
