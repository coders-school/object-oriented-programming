#include "player.hpp"
#include "constValues.hpp"
#include <numeric>

constexpr size_t START_MONEY = 1000;
constexpr size_t START_SPACE = 0;

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t space, Time* Publisher)
    : ship_(std::move(ship)), 
    money_(money), 
    availableSpace_(space),
    Publisher_(Publisher){
   this -> Publisher_ -> addObserver(this); 
    }

Player::Player(std::unique_ptr<Ship> ship, Time* Publisher)
    : Player(std::move(ship), START_MONEY, START_SPACE, Publisher) {}

size_t Player::getSpeed() const{
    if (ship_) {
        return ship_->getSpeed();
    }
    return 0;
}

Cargo* Player::getCargo(size_t cargo) const{
    if (ship_) {
        return ship_->getCargo(cargo);
    }
    return nullptr;
}

void Player::payCrew(size_t crew){
    money_ -= (constValues::dailySalary * crew);
}
void Player::nextDay(){
    payCrew(ship_->getCrew());
}

size_t Player::countAvailableSpace() {
     return ship_->countAvailableSpace(); 
}
