#include "player.hpp"

#include <numeric>

#include "constValues.hpp"

Player::Player(std::shared_ptr<Ship> ship, size_t money, size_t space, std::shared_ptr<Time> publisher)
    : ship_(ship), 
      money_(money), 
      availableSpace_(space),
      publisher_(publisher) {
          this->publisher_->addObserver(this); 
      }

size_t Player::getSpeed() const {
    if (ship_) {
        return ship_->getSpeed();
    }
    return 0;
}

void Player::giveMoney(size_t money) {
    money_ += money;
}

void Player::takeMoney(size_t money) {
    money_ -= money;
}

Alcohol* Player::getAlcoWithName(const std::string& name) {
    return ship_->findAlcoByName(name);
}

Fruit* Player::getFruitWithName(const std::string& name) {
    return ship_->findFruitByName(name);
}

Item* Player::getItemWithName(const std::string& name) {
    return ship_->findItemByName(name);
}

Cargo* Player::getCargo(size_t cargo) const {
    if (ship_) {
        return ship_->getCargo(cargo);
    }
    return nullptr;
}

void Player::payCrew(size_t crew) {
    money_ -= (constValues::dailySalary * (crew % 10));
}
void Player::nextDay(){
    payCrew(ship_->getCrew());
}

size_t Player::getAvailableSpace() { 
    return availableSpace_ = ship_->countAvailableSpace();
}

void Player::PurchaseCargo(std::shared_ptr<Cargo> cargo, size_t price, size_t amount) {
    availableSpace_ -= amount;
    takeMoney(price);
    ship_->load(cargo);
    *cargo -= amount;
}
