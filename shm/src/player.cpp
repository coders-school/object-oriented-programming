#include "player.hpp"

Player::Player(Ship& ship, size_t money, size_t availableSpace)
    : money_(money)
    , availableSpace_(availableSpace) {
    ship_ = std::make_unique<Ship>(ship);
}

std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    return ship_->getCargo(index); 
}
