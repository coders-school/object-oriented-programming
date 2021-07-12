#include "shm/inc/Player.hpp"

#include <numeric>

#include "shm/inc/Cargo.hpp"
#include "shm/inc/Map.hpp"

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_(std::move(ship)), money_(money)
{
    availableSpace_.first = true;
    availableSpace_.second = availableSpace;
    currentPosition_ = &map_->getIslands()[0];
}

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}
  
std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    if (ship_) {
        return ship_->getCargo(index);
    }
    return nullptr;
}

Island* Player::getCurrentPosition() const {
    return currentPosition_;
}

void Player::setCurrentPosition(Island* island) {
    currentPosition_ = island;
}

Cargo* Player::getCargo(const std::string& name) const {
    return ship_->getCargo(name);
}

size_t Player::countAvailableSpace() const {
    return availableSpace_.first
           ? availableSpace_.second
           : ship_->getCapacity() - 
             std::accumulate(ship_->getCargos().cbegin(),
                             ship_->getCargos().cend(),
                             static_cast<size_t>(0),
                             [](size_t sum, const auto& cargo) {
                                 return sum += cargo->getAmount();
                             });   
}

void Player::payCrew(const size_t payCrew) {
    money_ <= payCrew 
        ? money_ = 0 
        : money_ -= payCrew;
}

void Player::setPlayerPtr() {
    ship_->changeDelegate(this);
}
