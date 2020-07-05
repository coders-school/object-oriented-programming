#include "player.hpp"

#include <numeric>

constexpr size_t START_MONEY = 1000;
constexpr size_t START_SPACE = 0;

Player::Player(std::shared_ptr<Ship> ship, size_t money, size_t space)
    : ship_(std::move(ship)), money_(money), availableSpace_(space) {}

Player::Player(std::shared_ptr<Ship> ship)
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

Alcohol* Player::getAlcoWithName(const std::string& name){
    return ship_->findAlcoByName(name);
}

Fruit* Player::getFruitWithName(const std::string& name){
    return ship_->findFruitByName(name);
}

Item* Player::getItemWithName(const std::string& name){
    return ship_->findItemByName(name);
}

Cargo* Player::getCargo(size_t cargo) const{
    if (ship_) {
        return ship_->getCargo(cargo);
    }
    return nullptr;
}

void  Player::giveCargo(Alcohol* cargo){
    ship_->load(cargo);
}

void  Player::giveCargo(Fruit* cargo){
    ship_->load(cargo);
}

void  Player::giveCargo(Item* cargo){
    ship_->load(cargo);
}

void  Player::removeAlco(Alcohol* cargo){
    ship_->removeAlco(cargo);
}

void  Player::removeFruit(Fruit* cargo){
    ship_->removeFruit(cargo);
}

void  Player::removeItem(Item* cargo){
    ship_->removeItem(cargo);
}

size_t Player::countAvailableSpace(){
     return ship_->countAvailableSpace(); 
}

size_t Player::getAvailableSpace() { 
    return availableSpace_ + ship_->countAvailableSpace();
}
