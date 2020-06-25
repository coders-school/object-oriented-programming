#include "Player.hpp"

#include <algorithm>

Cargo* Player::getCargo(size_t index) const {
    if (index > (ship_->getCargo().size())){
        return nullptr;
    }
    return &ship_->getCargo()[index];
}

void Player::countAvailableSpace() {

    auto amoutOfCargo = ship_->getCargo().size();
    auto availableSpaceTmp = ship_->getCapacity() - amoutOfCargo;

    if(availableSpaceTmp <= 0)
        availableSpace_ = 0;
    else
        availableSpace_ = availableSpaceTmp;
}
