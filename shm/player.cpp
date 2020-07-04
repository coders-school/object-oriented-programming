#include "player.hpp"

#include <numeric>

constexpr size_t START_MONEY = 1000;
constexpr size_t START_SPACE = 0;

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t space)
    : ship_(std::move(ship)), money_(money), availableSpace_(space) {}

Player::Player(std::unique_ptr<Ship> ship)
    : Player(std::move(ship), START_MONEY, START_SPACE) {}

size_t Player::getSpeed() const{
    if (ship_) {
        return ship_->getSpeed();
    }
    return 0;
}

void Player::giveMoney(size_t money){
    money_ += money;
}

void Player::takeMoney(size_t money){
    money_ -= money;
}

Cargo* Player::getCargoWithName(std::string name){
    return ship_->findCargoByName(name);
}

Cargo* Player::getCargo(size_t cargo) const{
    if (ship_) {
        return ship_->getCargo(cargo);
    }
    return nullptr;
}

void  Player::giveCargo(Cargo* cargo){
    ship_->load(cargo);
}

void  Player::removeCargo(Cargo* cargo){
    ship_->removeCargo(cargo);
}

size_t Player::countAvailableSpace(){
     return ship_->countAvailableSpace(); 
}

size_t Player::getAvailableSpace() { 
    return availableSpace_ + ship_->countAvailableSpace();
}
