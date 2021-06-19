#include "../inc/Player.hpp"

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace)
    : ship_(std::move(ship)), money_(money), availableSpace_(availableSpace) 
{}

size_t Player::getSpeed() const {
    return ship_->getSpeed();
};

std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}
 
/*size_t Player::countAvailableSpace() const {
    size_t availableSpace = ship_->getCapacity();
    if (ship_) {
        for (size_t i = 0; i < ship_->getHowManyCargos(); i++) {
            availableSpace -= ship_->getCargo(i)->getAmount();
        }
    }
    return availableSpace;
}*/

size_t Player::countAvailableSpace() const {
    size_t usedSpace = 0;
    /*size_t usedSpace = std::accumulate(ship_->getVectorCargo().cbegin(), ship_->getVectorCargo().cend(), 0),
        [&](auto& rhs, auto& lhs){ return (*rhs + *lhs); };*/
    std::for_each(ship_->getVectorCargo().cbegin(), ship_->getVectorCargo().cend(), 
        [&usedSpace](const auto& ptrCargo){ usedSpace += *ptrCargo; });
    if (usedSpace<= ship_->getCapacity()) {
        return ship_->getCapacity() - usedSpace;
    }
    return 0;
}


