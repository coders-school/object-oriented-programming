#include "player.hpp"

Cargo* Player::getCargo(size_t index) const {
    if (index < (ship_->getCargo().size())) {
        return &ship_->getCargo()[index];
    } else {
        return nullptr;
    }
}
