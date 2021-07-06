#include "shm/inc/Player.hpp"

#include <numeric>

#include "shm/inc/Cargo.hpp"
#include "shm/inc/Ship.hpp"

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_(std::move(ship)), money_(money), availableSpace_(availableSpace) 
{}

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}
  
std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}

// TODO:
size_t Player::countAvailableSpace() const {
    return ship_->getCapacity() - 
            std::accumulate(ship_->getVectorCargo().cbegin(),
                    ship_->getVectorCargo().cend(),
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
