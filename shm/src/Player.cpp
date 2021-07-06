#include "shm/inc/Player.hpp"

#include <numeric>

#include "shm/inc/Cargo.hpp"

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_(std::move(ship)), money_(money)
{
    availableSpace_.first = true;
    availableSpace_.second = availableSpace;
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
